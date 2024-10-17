#include <stdio.h>
void main(){
	int i,j,n,at[10],bt[10],remain,flag=0,rt[10],time,ts,tat[10],wt[10],ct[10];
	float tottat=0,totwt=0;
	printf("Enter the number of process : ");
	scanf("%d",&n);
	
	remain=n;
	
	for(i=0;i<n;i++){
		printf("Enter the arrival time and burst time of process %d : ",i+1);
		scanf("%d%d",&at[i],&bt[i]);
		rt[i]=bt[i];
	}
	
	printf("Enter the time slice : ");
	scanf("%d",&ts);
	
	for(time=0,i=0;remain!=0;){
		if(rt[i]<=ts && rt[i]>0){
			time+=rt[i];
			rt[i]=0;
			flag=1;
		}
		
		else if(rt[i]>0){
			rt[i]-=ts;
			time+=ts;
		}
		
		if(rt[i]==0 && flag==1){
			remain--;
			ct[i]=time;
			tat[i]=ct[i]-at[i];
			wt[i]=tat[i]-bt[i];
			totwt+=wt[i];
			tottat+=tat[i];
			flag=0;
		}
		
		if(i==n-1)
		i=0;
		else if(at[i+1]<=time)
		i++;
		else
		i=0;
		
	}
	
	printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n\n");
	for(i=0;i<n;i++){
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
	}
	
	printf("\nAverage turn around time : %f",tottat/n);
	printf("\nAverage waiting time : %f",totwt/n);
}
