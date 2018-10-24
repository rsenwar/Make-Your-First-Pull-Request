#include <stdio.h>
#define RECORDS 10 // we can change this number to allow adding more players

struct BballPlayers {
  char playerName[30];
  char team[30];
  double salary;
}

int get_basketballPlayers(struct BballPlayers e[]);

int main() {
  int i, total_players = 0;
  struct BballPlayers e[RECORDS];

  total_players = get_basketballPlayers(e);
  for(i = 0; i < total_players; i++)
    printf("Player's name: %s\nTeam: %s\nSalary: %.2lf\n",
            e[i].playerName, e[i].team, e[i].salary);
  return 0;
}

int get_basketballPlayers(struct BballPlayers e[]) {
  int ind = 0, stop = 0;

  do {
    printf("Enter Player's name: ");
    scanf("%s", e[ind].playerName);
    printf("Enter Team name: ");
    scanf("%s", e[ind].team);
    printf("Salary: ");
    scanf("%lf", &e[ind].salary);
    ind++;
    if (ind < RECORDS) {
      printf("Add another player? (1 - yes / 0 - no)");
      scanf("%d", &stop);
    }
  } while (ind < RECORDS && stop == 1);
  
  return ind;
}