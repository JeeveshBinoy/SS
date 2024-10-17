#include <stdio.h>
#include <stdlib.h>
void main(){
int n, RQ[100],initial;
int totalheadmovements=0;

printf("Enter the number of requests : ");
scanf("%d",&n);

printf("Enter the request sequence : ");
for(int i=0;i<n;i++){
	scanf("%d",&RQ[i]);
}

printf("Enter the initial position : ");
scanf("%d",&initial);

for(int i=0;i<n;i++){
	totalheadmovements+=abs(RQ[i]-initial);
	initial=RQ[i];
}

printf("Total head movements : %d",totalheadmovements);
}
