#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
    char s[20], c;
    int state = 0, i = 0;
    
    printf("\nEnter the String: \n");
    gets(s);
    
    while(s[i] != '\0')
    {
        switch(state)
        {
                    //start
            case 0: c = s[i++];
                    if(c == 'a')
                        state = 1;
                    else if(c == 'b')
                        state = 2;
                    else
                        state  = 6;
                    break;
                    
                    //if a continues
            case 1: c = s[i++];
                    if(c == 'a')
                        state = 3;
                    else if(c == 'b')
                        state = 4;
                    else
                        state = 6;
                    break;
                    
                    //b's chain
            case 2: c = s[i++];
                    if(c == 'a')
                        state = 6;
                    else if(c == 'b' || c == '*')
                        state = 2;
                    else
                        state = 6;
                    break;
                    
                    // a's chain 
            case 3: c == s[i++];
                    if(c == 'a')
                        state = 3;
                    else if(c == 'b')
                        state = 2;
                    else
                        state = 6;
                    break;
                    
                    
            case 4: c == s[i++];
                    if(c == 'a')
                        state = 6;
                    else if(c =='b')
                        state = 5;
                    else
                        state = 6;
                    break;
            
            case 5: c = s[i++];
                    if(c == 'a')
                        state = 6;
                    else if(c == 'b' || c == '+')
                        state = 2;
                    else
                        state = 6;
                    break;
            case 6: printf("\n Invalid: \n");
                    exit(0);
        }
    }
    
    if(state == 1)
    {
        printf("\n %s is accepted under rule 'a'\n", s);
    }
    else if((state == 2) || (state == 4))
    {
        printf("\n %s is accepted under rule 'a*b+'\n", s);
    }
    else if(state == 5)
    {
        printf("\n %s is accepted under rule 'abb' \n", s);
    }
    else
    {
        printf("\n does not accepted with anything\n");
    }
}
