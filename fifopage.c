#include <stdio.h>
void main(){
	int i,j,k,n,rs[20],count=0,f,m[50],pf=0;
	printf("Enter the reference string length : ");
	scanf("%d",&n);
	
	printf("Enter the reference string : ");
	for(i=0;i<n;i++){
		scanf("%d",&rs[i]);
	}
	
	printf("Enter the number of frames : ");
	scanf("%d",&f);
	
	for(i=0;i<f;i++){
		m[i]=-1;
	}
	
	for(i=0;i<n;i++){
		for(k=0;k<f;k++){
			if(m[k]==rs[i]){
				break;
			}
		}
		
		if(k==f){
			m[count++]=rs[i];
			pf++;
		}
		
		if(count==f){
			count=0;
		}
		
		for(j=0;j<f;j++){
			printf("%d\t",m[j]);
		}
		
		printf("\n");
		
	}
	
	
	
	printf("\nPage faults : %d",pf);
	
	
}
