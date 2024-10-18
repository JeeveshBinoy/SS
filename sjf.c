#include <stdio.h>

struct sjf{
	int pid;
	int at;
	int ct;
	int bt;
	int tat;
	int wt;
}p[20];

void main(){
	int i,n,completed=0,time=0,min;
	float tottat=0,totwt=0;
	
	printf("Enter the number of process : ");
	scanf("%d",&n);
	
	printf("Enter the at and bt : ");
	for(i=0;i<n;i++){
		scanf("%d%d",&p[i].at,&p[i].bt);
		p[i].pid=i;
		p[i].ct=0;
	}
	
	while (completed<n){
		min=-1;
		for(i=0;i<n;i++){
			if(p[i].ct==0 && p[i].at<=time){
				if(p[i].bt<p[min].bt || min==-1){
					min = i;
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
        printf("%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].tat,p[i].wt);
    }
    printf("Avg TAT:%.2f",tottat/n);
    printf("Avg Wt:%.2f",totwt/n);
	
}

