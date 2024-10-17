#include <stdio.h>
void main(){
	int i,j,k,n,rs[20],m[20],used[20]={0},count=0,pf=0,f;
	
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
				used[k]=i+1;
				break;
			}
		}
		
		if(k==f){
			int mintime=used[0],minindex=0;
			for(j=0;j<f;j++){
				if(used[j]<mintime){
					mintime=used[j];
					minindex=j;
				}
			}
			
			m[minindex]=rs[i];
			used[minindex]=i+1;
			pf++;
		}
		
		for(j=0;j<f;j++){
			printf("%d\t",m[j]);
		}
		printf("\n");
	}
	
	printf("Page faults : %d",pf);
}
