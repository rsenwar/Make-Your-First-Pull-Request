#include<stdio.h>
 int main(){
    int t,y,ly,i;
    scanf("%d",&t);
    while(t--){
        ly=0;
        scanf("%d",&y);
        if(y>2001){
            for(i=2001;i<y;i++){
                if((i%4==0 && i%100!=0) || i%400==0)
                    ly+=2;
                else
                    ly++;
            }
            ly=(1+ly%7)%7;
        }
        else{
            for(i=y;i<2001;i++){
                if((i%4==0 && i%100!=0) || i%400==0)
                    ly+=2;
                else
                    ly++;
            }
            ly=(8-ly%7)%7;
        }

    switch(ly){
    case 0:
        printf("sunday\n");
        break;
    case 1:
        printf("monday\n");
        break;
    case 2:
        printf("tuesday\n");
        break;
    case 3:
        printf("wednesday\n");
        break;
    case 4:
        printf("thursday\n");
        break;
    case 5:
        printf("friday\n");
        break;
    case 6:
        printf("saturday\n");
        break;
  }
 }
 return 0;
}
