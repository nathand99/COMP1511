// DO NOT CHANGE THIS FILE
// DO NOT ADD LINES TO THIS FILE
// DO NOT DELETE LINES FROM THIS FILE
// DO NOT CHANGE THIS FILE

// Fruit Bot - https://cgi.unsw.edu.au/~cs1511/assignments/ass3/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#include "fruit_bot.h"


#define FRUIT_MARKER " kg of "
#define ALTERNATE_FRUIT_MARKER " kJ of "
#define FRUIT_END_MARKER " for "
#define BATTERY_MARKER "battery level: "
#define TURN_MARKER "*** Turn "
#define TURN_NEXT_MARKER " of "
#define YOU_ARE_MARKER "*** You are"
#define MAX_LINE_CHARS 65536

static int parse_starting_parameter(char line[], struct bot *prototype_bot);
static int parse_turn(char line[], struct bot *prototype_bot, int n_bots, struct bot *bots[MAX_BOTS]);
static struct bot *parse_you_are(char line[], int n_bots, struct bot *bots[MAX_BOTS]);
static struct location *parse_location(char line[], int n_locations, struct location *locations[MAX_LOCATIONS]);
static struct bot *parse_bot(char line[], struct bot *prototype_bot,
                               int n_locations, struct location *locations[MAX_LOCATIONS]);
static char *sstrdup(char *s);
static void *salloc(size_t n_bytes);

// read a decsription of fruit bot from stdin
// return NULL if no description can be read

struct bot *fruit_bot_input(FILE *stream) {
    int debug = 0;
    char line[MAX_LINE_CHARS];
    struct bot prototype_bot = {
            .cash=100,
            .battery_level=100,
            .maximum_move=7,
            .maximum_fruit_kg=15,
            .battery_capacity=100,
            .turns_left=100
        };
    int n_locations = 0;
    struct location *locations[MAX_LOCATIONS];
    int n_bots = 0;
    struct bot *bots[MAX_BOTS];
    struct bot *me = NULL;

    while (fgets(line, sizeof line, stream) != NULL) {
        // trim trailing white space
        char *p = line + strlen(line) - 1;
        while (p >= line && isspace(*p)) {
            *p = '\0';
            p = p - 1;
        }
        char original_line[MAX_LINE_CHARS];
        strncpy(original_line, line, MAX_LINE_CHARS);
        original_line[MAX_LINE_CHARS - 1] = '\0';
        if (debug) {
            fprintf(stderr, "line='%s'\n", line);
        }
        int parse_result = 1;
        if (line[0] != '"' && line[0] != '*' && !isalpha(line[0])) {
            // skip line
        } else if (strncmp(line, TURN_MARKER, strlen(TURN_MARKER)) == 0) {
            parse_result = parse_turn(line, &prototype_bot, n_bots, bots);
        } else if (strncmp(line, YOU_ARE_MARKER, strlen(YOU_ARE_MARKER)) == 0) {
            me = parse_you_are(line, n_bots, bots);
            parse_result = !!me;
        } else if (line[0] == '"') {
            assert(n_bots  < MAX_BOTS);
            bots[n_bots] = parse_bot(line, &prototype_bot, n_locations, locations);
            parse_result = !!bots[n_bots];
            n_bots++;
        } else if (strchr(line, ':')) {
            assert(n_locations  < MAX_LOCATIONS);
            locations[n_locations] = parse_location(line, n_locations, locations);
            parse_result = !!locations[n_locations];
            n_locations++;
        } else if (!n_locations && strchr(line, '=')) {
            parse_result = parse_starting_parameter(line, &prototype_bot);
        }
        if (!parse_result) {
            fprintf(stderr, "Error: bad line in world description: '%s'\n", original_line);
            exit(1);
        }
        if (debug) {
            fprintf(stderr, "parse_result=%d n_bots=%d n_locations=%d me=%p\n", parse_result, n_bots, n_locations, me);
        }
    }

    for (int i = 0; i < n_locations; i++) {
        locations[i]->east = locations[(i + 1) % n_locations];
        locations[i]->west = locations[(n_locations + i - 1) % n_locations];
    }

    if (me) {
        return me;
    }

    if (n_bots) {
        return bots[0];
    }

    return NULL;
}

// parse a line saying what simulation turn this and update all bots appropriately
// return 1, if successful, 0 otherwise

static int parse_turn(char line[], struct bot *prototype_bot, int n_bots, struct bot *bots[MAX_BOTS]) {
    char *p = strstr(line, TURN_MARKER);
    if (!p) {
        fprintf(stderr, "Error: missing turn marker\n");
        return 0;
    }
    p += strlen(TURN_MARKER);
    int turn = atoi(p);
    if (!turn) {
        fprintf(stderr, "Error: turn\n");
        return 0;
    }
    p = strstr(p, TURN_NEXT_MARKER);
    if (!p) {
        fprintf(stderr, "Error: missing turn next marker\n");
        return 0;
    }
    p += strlen(TURN_NEXT_MARKER);
    int n_turns = atoi(p);
    if (!n_turns) {
        fprintf(stderr, "Error: missing n_turn\n");
        return 0;
    }
    int turns_left = n_turns - turn + 1;
    prototype_bot->turns_left = turns_left;
    for (int i = 0; i < n_bots; i++) {
        bots[i]->turns_left = turns_left;
    }
    return 1;
}

static struct bot *parse_you_are(char line[], int n_bots, struct bot *bots[MAX_BOTS]) {
    char *p = strchr(line, '"');
    if (!p) {
        fprintf(stderr, "Error: you are line missing opening quote\n");
        return NULL;
    }
    p++;
    char *q = strchr(p, '"');
    if (!q) {
        fprintf(stderr, "Error: you are line missing closing quote\n");
        return NULL;
    }
    *q = '\0';

    for (int i = 0; i < n_bots; i++) {
        if (strcmp(bots[i]->name, p) == 0) {
            return bots[i];
        }
    }
    fprintf(stderr, "Error: you are line bot '%s' not found\n", p);
    return NULL;
}

// parse a line specifying a simulation parameter and update prototype bot appropriately
// return 1, if successful, 0 otherwise

static int parse_starting_parameter(char line[], struct bot *prototype_bot) {
    char *p = strchr(line, '=');
    if (!p || p == line) {
        return 0;
    }
    while (isspace(*p) && p > line) {
        p--;
    }
    *p = '\0';
    int value = atoi(p + 1);
    if (value == 0) {
        return 0;
    }
    if (strcmp(line, "cash") == 0) {
        prototype_bot->cash = value;
    } else if (strcmp(line, "battery_capacity") == 0) {
        prototype_bot->battery_capacity = value;
        prototype_bot->battery_level = value;
    } else if (strcmp(line, "cash") == 0) {
        prototype_bot->cash = value;
    } else if (strcmp(line, "maximum_move") == 0) {
        prototype_bot->maximum_move = value;
    } else if (strcmp(line, "maximum_fruit_kg") == 0) {
        prototype_bot->maximum_fruit_kg = value;
    }
    return 1;
}

static struct location *parse_location(char line[], int n_locations, struct location *locations[MAX_LOCATIONS]) {
    struct location *l = salloc(sizeof *l);
    char *p = strchr(line, ':');
    if (!p) {
        fprintf(stderr, "error: can not find name in location description\n");
        return NULL;
    }
    *p = '\0';
    l->name = sstrdup(line);
    for (int i = 0; i < n_locations; i++) {
        if (strcmp(locations[i]->name, l->name) == 0) {
            fprintf(stderr, "warning: ignoring duplicate location description '%s'\n", l->name);
            free(l->name);
            free(l);
            return locations[i];
        }
    }
    assert(n_locations < MAX_LOCATIONS);
    locations[n_locations++] = l;
    p = p + 1;
    char *q = strchr(p, '$');
    if (q) {
        l->price = atoi(q + 1);
        if (!l->price) {
            fprintf(stderr, "error: can not find price in location description\n");
            return NULL;
        }
    }
    q = NULL;
    q = strstr(p, "sell");
    if (q) {
        l->price = -l->price;
    } else {
        q = strstr(p, "buy");
    }

    if (!q) {
        l->fruit = sstrdup("Nothing");
        return l;
    }

    p = q + strlen("buy") + 1;
    l->quantity = atoi(p);

    q = strstr(p, FRUIT_MARKER);
    if (q) {
        p = q;
    } else {
        p = strstr(p, ALTERNATE_FRUIT_MARKER);
    }
    if (!p) {
        return l;
    }
    p += strlen(FRUIT_MARKER);
    q = strstr(p, FRUIT_END_MARKER);
    if (q) {
        *q = '\0';
    }
    l->fruit = sstrdup(p);
    return l;
}

static struct bot *parse_bot(char line[], struct bot *prototype_bot,
                               int n_locations, struct location *locations[MAX_LOCATIONS]) {

    struct bot *b = salloc(sizeof *b);

    *b = *prototype_bot;

    char *p = strchr(line + 1, '"');
    if (!p) {
        fprintf(stderr, "error: can not find closing quote for bot name\n");
        return NULL;
    }
    *p = '\0';
    b->name = sstrdup(line + 1);

    p = strchr(p + 1, '"');
    if (!p) {
        fprintf(stderr, "error: can not find location for bot\n");
        return NULL;
    }
    p++;
    char *q =  strchr(p, '"');
    if (!q) {
        fprintf(stderr, "error: can not find closing quote for bot location\n");
        return NULL;
    }
    *q = 0;

    int i = 0;
    while (i < n_locations) {
        //fprintf(stderr, "locations[i]->name='%s' p='%s'\n", locations[i]->name, p);
        if (strcmp(locations[i]->name, p) == 0) {
            break;
        }
        i++;
    }
    if (i == n_locations) {
        fprintf(stderr, "error: unknown location '%s' \n", p);
        return NULL;
    }

    b->location = locations[i];
    struct bot_list *bl = salloc(sizeof *bl);
    bl->bot = b;
    bl->next = b->location->bots;
    b->location->bots = bl;

    p = strchr(q + 1, '$');
    if (!p) {
        fprintf(stderr, "error: can not find bot cash\n");
        return NULL;
    }
    b->cash = atoi(p + 1);

    p = strstr(p, BATTERY_MARKER);
    if (!p) {
        fprintf(stderr, "error: can not find bot battery level\n");
        return NULL;
    }
    p += strlen(BATTERY_MARKER);
    b->battery_level = atoi(p);

    p = strchr(p, ',');
    if (!p) {
        return b;
    }
    p++;
    b->fruit_kg = atoi(p);
    if (!b->fruit_kg) {
        fprintf(stderr, "Can not find bot fruit kg\n");
        return NULL;
    }

    p = strstr(p, FRUIT_MARKER);
    if (!p) {
        fprintf(stderr, "error: can not find bot frtui\n");
        return NULL;
    }
    p += strlen(FRUIT_MARKER);

    q = strchr(p, ':');
    if (q) {
        *q = '\0';
    }
    b->fruit = sstrdup(p);
    return b;
}

static char *sstrdup(char *s) {
    char *p = strdup(s);
    assert(p);
    return p;
}

static void *salloc(size_t n_bytes) {
    void *p = malloc(n_bytes);
    assert(p);
    memset(p, 0, n_bytes);
    return p;
}
