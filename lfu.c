#include <stdio.h>
void main(){
	int i,j,k,n,count=0,pf=0,f;
	int rs[20],m[20],freq[20]={0};
	
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
		k=-1;
		for(j=0;j<f;j++){
			if(m[j]==rs[i]){
				k=j;
				freq[k]++;
				break;
			}
		}
		
		if(k==-1){
			int minfreq=freq[0],minindex=0;
			for(j=1;j<f;j++){
				if(freq[j]<minfreq){
					minfreq=freq[j];
					minindex=j;
				}
			}
			m[minindex]=rs[i];
			freq[minindex]=1;
			pf++;
		}
		else{
			freq[k]++;
		}
		
		for(j=0;j<f;j++){
			printf("%d\t",m[j]);
		}
		printf("\n");
	}
	
	printf("\nPage faults : %d",pf);
	
}
