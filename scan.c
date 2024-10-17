#include <stdio.h>
#include <stdlib.h>

void main(){
int i,j,n,RQ[100],size,move,initial,temp=0,totalhead=0,index=0;
printf("Enter the number of requests : ");
scanf("%d",&n);

printf("Enter the request sequence : ");
for(i=0;i<n;i++){
scanf("%d",&RQ[i]);
}

printf("Enter the initial head position : ");
scanf("%d",&initial);

printf("Enter the total disk size : ");
scanf("%d",&size);

printf("Enter the head movement direction 1 for high and 0 for low : ");
scanf("%d",&move);


for(i=0;i<n;i++){
	for(j=0;j<n-i-1;j++){
		if(RQ[j]>RQ[j+1]){
			temp=RQ[j];
			RQ[j]=RQ[j+1];
			RQ[j+1]=temp;
		}
	}
}

for(i=0;i<n;i++){
	if(initial<RQ[i]){
		index=i;
		break;
	}
}

if(move==1){
	for(i=index;i<n;i++){
		totalhead+=abs(RQ[i]-initial);
		initial=RQ[i];
	}
	
	totalhead+=abs(size-1-initial);
	initial=size-1;
	
	for(i=index-1;i>=0;i--){
		totalhead+=abs(RQ[i]-initial);
		initial=RQ[i];
	}
}

else{
	for(i=index-1;i>=0;i--){
		totalhead+=abs(RQ[i]-initial);
		initial=RQ[i];
	}
	
	totalhead+=abs(initial-0);
	initial=0;
	
	for(i=index;i<n;i++){
		totalhead+=abs(RQ[i]-initial);
		initial=RQ[i];
	}
}

printf("Total head movements : %d",totalhead);

}
