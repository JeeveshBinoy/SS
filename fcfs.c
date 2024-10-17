#include <stdio.h>
void main(){
	int n,at[100],bt[100],ct[100],tat[100],wt[100],i;
	float ttat=0,twt=0;
	
	printf("Enter the number of process : ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		printf("Enter the arrival time of process %d : ",i+1);
		scanf("%d",&at[i]);
	}
	
	for(i=0;i<n;i++){
		printf("Enter the burst time of process %d : ",i+1);
		scanf("%d",&bt[i]);
	}
	
	ct[0]=bt[0]-at[0];
	
	for(i=1;i<n;i++){
		ct[i]=ct[i-1]+bt[i];
	}
	
	for(i=0;i<n;i++){
		tat[i]=ct[i]-at[i];
		ttat+=tat[i];
	}
	
	for(i=0;i<n;i++){
		wt[i]=tat[i]-bt[i];
		twt+=wt[i];
	}
	printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n\n");
	for(i=0;i<n;i++){
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
	}
	
	printf("\nAverage turn around time : %f",ttat/n);
	printf("\nAverage waiting time : %f",twt/n);
}
