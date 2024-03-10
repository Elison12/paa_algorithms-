#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int skill;
} Player;

int cmp_skills(const void* a, const void* b) {
    const Player* p1 = (const Player*) a;
    const Player* p2 = (const Player*) b;
    return p2->skill - p1->skill; // sort in descending order
}

int cmp_names(const void* a, const void* b) {
    const char* s1 = (const char*) a;
    const char* s2 = (const char*) b;
    return strcmp(s1, s2);
}

void assign_teams(Player* players, int num_players, int num_teams) {
    // Sort players by skill level
    qsort(players, num_players, sizeof(Player), cmp_skills);

    // Allocate memory for team names and counts
    char** team_names = malloc(num_teams * sizeof(char*));
    int* team_counts = malloc(num_teams * sizeof(int));
    for (int i = 0; i < num_teams; i++) {
        team_names[i] = malloc(MAX_NAME_LENGTH * sizeof(char));
        memset(team_names[i], 0, MAX_NAME_LENGTH * sizeof(char)); // initialize memory to zero
    }

    // Assign players to teams
    int current_team = 0;
    for (int i = 0; i < num_players; i++) {
        // Add player to current team
        strncpy(team_names[current_team] + team_counts[current_team] * MAX_NAME_LENGTH,
                players[i].name, MAX_NAME_LENGTH);
        team_counts[current_team]++;

        // Move to next team if current team has enough players
        if (team_counts[current_team] >= num_players / num_teams + (current_team < num_players % num_teams)) {
            current_team++;
        }
    }

    // Sort team rosters alphabetically
    for (int i = 0; i < num_teams; i++) {
        qsort(team_names[i], team_counts[i], MAX_NAME_LENGTH * sizeof(char), cmp_names);
    }

    // Print team rosters
    for (int i = 0; i < num_teams; i++) {
        printf("Time %d:\n", i + 1);
        for (int j = 0; j < team_counts[i]; j++) {
            printf("%s\n", team_names[i] + j * MAX_NAME_LENGTH);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < num_teams; i++) {
        free(team_names[i]);
    }
    free(team_names);
    free(team_counts);
}

int main() {
    int num_players, num_teams;
    scanf("%d %d", &num_players, &num_teams);

    Player* players = malloc(num_players * sizeof(Player));
    for (int i = 0; i < num_players; i++) {
        scanf("%s %d", players[i].name, &players[i].skill);
    }

    assign_teams(players, num_players, num_teams);

    free(players);
    return 0;
}
