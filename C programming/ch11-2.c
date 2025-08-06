#include <stdio.h>
#include <stdlib.h>
/*
8
8:00 a.m. 10:16 a.m.
9:43 a.m. 11:52 a.m.
11:19 a.m. 1:31 p.m.
12:47 p.m. 3:00 p.m.
2:00 p.m. 4:08 p.m.
3:45 p.m. 5:55 p.m.
7:00 p.m. 9:20 p.m.
9:45 p.m. 11:58 p.m.
13:15
*/

int N;

void find_closet_flight(int desired_time, int *departure_time, int *arrival_time){
    int minn=25*60;
    int f=0;
    for(int i=0; i<N; i++){
        if(desired_time < *(departure_time+i)){
            if(*(departure_time+i)-desired_time < minn){
                minn = *(departure_time+i) - desired_time;
                f=i;
            }
        }else{
            if(desired_time - *(departure_time+i) < minn){
                minn = desired_time - *(departure_time+i);
                f=i;
            }
        }
    }
    int d1=*(departure_time+f)/60;
    int d2=*(departure_time+f)%60;
    int a1=*(arrival_time+f)/60;
    int a2=*(arrival_time+f)%60;
    if(d1>12){
        printf("Closest departure time is %2d:%02d p.m.", d1-12, d2);
    }else if(d1==12){
        printf("Closest departure time is %2d:%02d p.m.", d1, d2);
    }else{
        printf("Closest departure time is %2d:%02d a.m.", d1, d2);
    }
    if(a1>12){
        printf(", arriving at %2d:%02d p.m.", a1-12, a2);
    }else if(a1==12){
        printf(", arriving at %2d:%02d p.m.", a1, a2);
    }else{
        printf(", arriving at %2d:%02d a.m.", a1, a2);
    }
}


int main(){
    scanf("%d\n", &N);
    int *d= malloc(N*sizeof(int));
    int *a= malloc(N*sizeof(int));
    int h1,m1,h2,m2;
    char ch1,ch2;
    for(int i=0; i<N; i++){
        scanf("%d:%d %c.m. %d:%d %c.m.\n", &h1, &m1, &ch1, &h2, &m2, &ch2);
        if(ch1=='a'||h1==12){
            *(d+i) = h1*60+m1;
        }else{
            *(d+i) = h1*60+m1+720;
        }
        if(ch2=='a'||h2==12){
            *(a+i) = h2*60+m2;
        }else{
            *(a+i) = h2*60+m2+720;
        }
    }
    scanf("%d:%d", &h1, &m1);
    find_closet_flight(h1*60+m1, d, a);

    return 0;
}