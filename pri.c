#include <stdio.h>

struct P{
	int pid;
	int at;
	int bt;
	int ct;
	int tat;
	int wt;
	int pri;
}p[20];

void main(){
	int i, n,completed=0,time=0,min;
	float tottat=0,totwt=0;
	
	printf("Enter the number of process : ");
	scanf("%d",&n);
	printf("Enter the at,bt, pri: ");
	for(i=0;i<n;i++){
		scanf("%d%d%d",&p[i].at,&p[i].bt,&p[i].pri);
		p[i].pid=i;
		p[i].ct=0;
	}
	
	while(completed<n){
		min =-1;
		for(i=0;i<n;i++){
		if(p[i].at<=time && p[i].ct==0){
			if(min==-1 || p[i].pri<p[min].pri){
				min=i;
			}
		}
	}
	
	if(min==-1){
		time++;
	}
	else{
		p[min].ct=time+p[min].bt;
		p[min].tat=p[min].ct-p[min].at;
		p[min].wt=p[min].tat-p[min].bt;
		time=p[min].ct;
		tottat+=p[min].tat;
		totwt+=p[min].wt;
		completed++;
	}
}
	printf("P\tBT\tAT\tPr\tWT\tTAT\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].bt,p[i].at,p[i].pri,p[i].wt,p[i].tat);
    }
    printf("Avg TAT:%.2f",tottat/n);
    printf("Avg Wt:%.2f",totwt/n);
	
}
