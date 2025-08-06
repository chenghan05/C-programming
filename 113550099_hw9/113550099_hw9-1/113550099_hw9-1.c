#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define allstr(i) (team[(i)].players[0].str+team[(i)].players[1].str+team[(i)].players[2].str+team[(i)].players[3].str+team[(i)].players[4].str) 
#define allluk(i) (team[(i)].players[0].luk+team[(i)].players[1].luk+team[(i)].players[2].luk+team[(i)].players[3].luk+team[(i)].players[4].luk)
#define lukofTMJ(i) (team[(i)].players[0].luk+team[(i)].players[1].luk+team[(i)].players[4].luk)
#define strofTMJ(i) (team[(i)].players[0].str+team[(i)].players[1].str+team[(i)].players[4].str)
#define lukofAS(i) (team[(i)].players[2].luk+team[(i)].players[3].luk)
#define strofAS(i) (team[(i)].players[2].str+team[(i)].players[3].str)

typedef struct{
    char name[21];
    int str,luk;
} Player;

typedef struct{
	char team_name[21];
	Player players[5];
	int history[20], winid[20], id, moles;
    int now;
} Team;

Team team[1050];

void balance(int w, int lo){
    for(int i=0; i<5; i++){
        team[w].players[i].luk = (team[w].players[i].luk - 5 + 100) % 100;
        team[lo].players[i].luk = (team[lo].players[i].luk + 5 + 100) % 100;
    }
}

int duel(int l, int r){
    if(l == r) return l;
    if(l < r) return duel(duel((l+r)/2+1, r), duel(l, (l+r)/2));
    int lwin=0, rwin=0;
    //round 1
    if(allstr(l)+allluk(l) == allstr(r)+allluk(r)){ rwin++; balance(r, l);
    }else if(allstr(l)+allluk(l) > allstr(r)+allluk(r)){ lwin++; balance(l ,r);
    }else{ rwin++; balance(r, l);}
//    printf("%d,%d,%d,%d,%d,%d ,%d, %d, %d\n", l,team[l].players[0].luk,  team[l].players[1].luk,  team[l].players[2].luk,  team[l].players[3].luk,  team[l].players[4].luk, allluk(l), lukofTMJ(l), lukofAS(l));
//    printf("%d,%d,%d,%d,%d,%d ,%d, %d, %d\n", r,team[r].players[0].luk,  team[r].players[1].luk,  team[r].players[2].luk,  team[r].players[3].luk,  team[r].players[4].luk, allluk(r), lukofTMJ(r), lukofAS(r));
    //round 2
    if(strofTMJ(l)+lukofTMJ(l) == strofTMJ(r)+lukofTMJ(r)){ rwin++; balance(r, l);}
    else if(strofTMJ(l)+lukofTMJ(l) > strofTMJ(r)+lukofTMJ(r)){ lwin++; balance(l ,r);}
    else{ rwin++; balance(r, l);}
//    printf("%d,%d,%d,%d,%d,%d ,%d, %d, %d\n", l,team[l].players[0].luk,  team[l].players[1].luk,  team[l].players[2].luk,  team[l].players[3].luk,  team[l].players[4].luk, allluk(l), lukofTMJ(l), lukofAS(l));
//    printf("%d,%d,%d,%d,%d,%d ,%d, %d, %d\n", r,team[r].players[0].luk,  team[r].players[1].luk,  team[r].players[2].luk,  team[r].players[3].luk,  team[r].players[4].luk, allluk(r), lukofTMJ(r), lukofAS(r));
    //round 3
    if(strofAS(l)+lukofAS(l) == strofAS(r)+lukofAS(r)){ rwin++; balance(r, l);}
    else if(strofAS(l)+lukofAS(l) > strofAS(r)+lukofAS(r)){ lwin++; balance(l ,r);}
    else{ rwin++; balance(r, l);}
//    printf("%d,%d,%d,%d,%d,%d ,%d, %d, %d\n", l,team[l].players[0].luk,  team[l].players[1].luk,  team[l].players[2].luk,  team[l].players[3].luk,  team[l].players[4].luk, allluk(l), lukofTMJ(l), lukofAS(l));
//    printf("%d,%d,%d,%d,%d,%d ,%d, %d, %d\n", r,team[r].players[0].luk,  team[r].players[1].luk,  team[r].players[2].luk,  team[r].players[3].luk,  team[r].players[4].luk, allluk(r), lukofTMJ(r), lukofAS(r));
    //round 4
    if(lwin<3 && rwin<3){
        if(team[l].moles == team[r].moles){ rwin++; balance(r, l);}
        else if(team[l].moles < team[r].moles){ lwin++; balance(l ,r);}
        else{ rwin++; balance(r, l);}
//        printf("%d,%d,%d,%d,%d,%d ,%d, %d, %d\n", l,team[l].players[0].luk,  team[l].players[1].luk,  team[l].players[2].luk,  team[l].players[3].luk,  team[l].players[4].luk, allluk(l), lukofTMJ(l), lukofAS(l));
//        printf("%d,%d,%d,%d,%d,%d ,%d, %d, %d\n", r,team[r].players[0].luk,  team[r].players[1].luk,  team[r].players[2].luk,  team[r].players[3].luk,  team[r].players[4].luk, allluk(r), lukofTMJ(r), lukofAS(r));
    }
    
    //round 5
    if(lwin<3 && rwin<3){
        int lmstr = -2000, rmstr = -2000; 
        int lmluk = -1, rmluk = -1;
        for(int i=0; i<5; i++){
            if(team[l].players[i].str > lmstr) lmstr = team[l].players[i].str;
            if(team[r].players[i].str > rmstr) rmstr = team[r].players[i].str; 
            if(team[l].players[i].luk > lmluk) lmluk = team[l].players[i].luk; 
            if(team[r].players[i].luk > rmluk) rmluk = team[r].players[i].luk;  
        }
        if(lmstr*lmluk == rmstr*rmluk){ rwin++; balance(r, l);}
        else if(lmstr*lmluk > rmstr*rmluk){ lwin++; balance(l ,r);}
        else{ rwin++; balance(r, l);}
//        printf("%d,%d,%d,%d,%d,%d ,%d, %d, %d\n", l,team[l].players[0].luk,  team[l].players[1].luk,  team[l].players[2].luk,  team[l].players[3].luk,  team[l].players[4].luk, allluk(l), lukofTMJ(l), lukofAS(l));
//        printf("%d,%d,%d,%d,%d,%d ,%d, %d, %d\n", r,team[r].players[0].luk,  team[r].players[1].luk,  team[r].players[2].luk,  team[r].players[3].luk,  team[r].players[4].luk, allluk(r), lukofTMJ(r), lukofAS(r));
    }

    if(lwin>rwin){
        team[l].history[team[l].now] = rwin;
        team[l].winid[team[l].now] = r;
        team[l].now++;
        return l;
    }else{
        team[r].history[team[r].now] = lwin;
        team[r].winid[team[r].now] = l;
        team[r].now++;
        return r;
    }
}

void print_win(int a, int n){
    printf("%s win from %d teams\n", team[a].team_name, n);
    for(int i=0; i<team[a].now; i++){
        printf("%s vs %s 3:%d\n", team[a].team_name, team[team[a].winid[i]].team_name, team[a].history[i]);
    }
    printf("Congratulations to");
    for(int i=0; i<5; i++){
        printf(" %s", team[a].players[i].name);
        if(i!=4) printf(",");
    }
    printf(" for winning the world championship!");
}

int main(){
    int n;
    scanf("%d", &n);    
    for(int i=0; i<n; i++){
        int num;
        char str[200];
        scanf("%s %d", str, &num);
        team[num].id = num;
        strcpy(team[num].team_name, str);
        team[num].now = 0;
        team[num].moles = 0;
        for(int j=0; j<5; j++){
            scanf("%s%d%d", team[num].players[j].name, &team[num].players[j].str, &team[num].players[j].luk);
            if(team[num].players[j].str < 0) team[num].moles++;
        }
    }
    int winner = duel(1, n);
    print_win(winner, n);

    return 0;
}