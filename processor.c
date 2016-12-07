
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int pc=0,m,j,k,t0,op1,op2,s0,d0,d1,d2,d3;
	char fil[20];
	int r0,r1,r2,r3;
	char mem[128][8];
	char output[8];
	FILE *inputfile;
	int oprevpcous, oprev, opnext,condr;
	int jumpadr,looptimes,printadr,begzadr,jaladr,loadadr,stadr,ifjadr;
	
		
	int o1,o2,op,operand1,operand2,j0,n=0;
/************************************copying code in memory******************************************************************/
		
	printf("Enter the name of txt file which you want to load:");
	scanf("%s",fil);
	
	 inputfile=fopen(fil,"r");
        while(!feof(inputfile))
        {
        fscanf(inputfile, "%s",mem[pc]);
        pc++;       
        m++;
        }
        fclose(inputfile);

/*********************************fetching instructpcon one by one decoding and implementig**************************************/

	for(pc=0;pc<64;pc++)
	{
		op = (mem[pc][0]-48)*8+(mem[pc][1]-48)*4+(mem[pc][2]-48)*2+(mem[pc][3]-48)*1;
		opnext=(mem[pc+1][0]-48)*8+(mem[pc+1][1]-48)*4+(mem[pc+1][2]-48)*2+(mem[pc+1][3]-48)*1;
		operand1 = (mem[pc][4]-48)*2+(mem[pc][5]-48)*1;
		operand2 = (mem[pc][6]-48)*2+(mem[pc][7]-48)*1;

/**********************************loading***************************************************************************************/

		if(op==12 && opnext !=14)
		{
			o1=(mem[pc-1][4]-48)*2+(mem[pc-1][5]-48)*1;
			loadadr=64+(mem[pc-1][6]-48)*32+(mem[pc-1][7]-48)*16+(mem[pc][4]-48)*8+(mem[pc][5]-48)*4+(mem[pc][6]-48)*2+(mem[pc][7]-48)*1;
			if(o1==0)
			{
				r0=(mem[loadadr][0]-48)*128+(mem[loadadr][1]-48)*pc+(mem[loadadr][2]-48)*32+(mem[loadadr][3]-48)*16+(mem[loadadr][4]-48)*8+(mem[loadadr][5]-48)*4+(mem[loadadr][6]-48)*2+(mem[loadadr][7]-48)*1;
				
			}
			if(o1==1)
			{
				r1=(mem[loadadr][0]-48)*128+(mem[loadadr][1]-48)*pc+(mem[loadadr][2]-48)*32+(mem[loadadr][3]-48)*16+(mem[loadadr][4]-48)*8+(mem[loadadr][5]-48)*4+(mem[loadadr][6]-48)*2+(mem[loadadr][7]-48)*1;
			}
			if(o1==2)
			{
				r2=(mem[loadadr][0]-48)*128+(mem[loadadr][1]-48)*pc+(mem[loadadr][2]-48)*32+(mem[loadadr][3]-48)*16+(mem[loadadr][4]-48)*8+(mem[loadadr][5]-48)*4+(mem[loadadr][6]-48)*2+(mem[loadadr][7]-48)*1;
			}
			if(o1==3)
			{
				r3=(mem[loadadr][0]-48)*128+(mem[loadadr][1]-48)*pc+(mem[loadadr][2]-48)*32+(mem[loadadr][3]-48)*16+(mem[loadadr][4]-48)*8+(mem[loadadr][5]-48)*4+(mem[loadadr][6]-48)*2+(mem[loadadr][7]-48)*1;
			}
			
			
			/*op1 = (mem[pc+1][0]-48)*8+(mem[pc+1][1]-48)*4+(mem[pc+1][2]-48)*2+(mem[pc+1][3]-48)*1;
			op2 = (mem[pc+2][0]-48)*8+(mem[pc+2][1]-48)*4+(mem[pc+2][2]-48)*2+(mem[pc+2][3]-48)*1;
			o1 = (mem[pc+2][4]-48)*2+(mem[pc+2][5]-48)*1;
		        o2 = (mem[pc+1][6]-48)*2+(mem[pc+1][7]-48)*1;
		    if(op2==1||op2==2||op2==3||op2==4||op2==5||op2==0)
		    {
			if(o1==0)
			{
			
				t0=64+(mem[pc][4]-48)*32+(mem[pc][5]-48)*16+(mem[pc][6]-48)*8+(mem[pc][7]-48)*4+o1;
				r0=(mem[t0][0]-48)*128+(mem[t0][1]-48)*pc+(mem[t0][2]-48)*32+(mem[t0][3]-48)*16+(mem[t0][4]-48)*8+(mem[t0][5]-48)*4+(mem[t0][6]-48)*2+(mem[t0][7]-48)*1;
			}
			if(o1==1)
			{
				t0=64+(mem[pc][4]-48)*32+(mem[pc][5]-48)*16+(mem[pc][6]-48)*8+(mem[pc][7]-48)*4+o1;
				r1=(mem[t0][0]-48)*128+(mem[t0][1]-48)*pc+(mem[t0][2]-48)*32+(mem[t0][3]-48)*16+(mem[t0][4]-48)*8+(mem[t0][5]-48)*4+(mem[t0][6]-48)*2+(mem[t0][7]-48)*1;
				
			}
			if(o1==2)
			{
				t0=64+(mem[pc][4]-48)*32+(mem[pc][5]-48)*16+(mem[pc][6]-48)*8+(mem[pc][7]-48)*4+o1;
				r2=(mem[t0][0]-48)*128+(mem[t0][1]-48)*pc+(mem[t0][2]-48)*32+(mem[t0][3]-48)*16+(mem[t0][4]-48)*8+(mem[t0][5]-48)*4+(mem[t0][6]-48)*2+(mem[t0][7]-48)*1;
			}
			if(o1==3)
			{
				t0=64+(mem[pc][4]-48)*32+(mem[pc][5]-48)*16+(mem[pc][6]-48)*8+(mem[pc][7]-48)*4+o1;
				r3=(mem[t0][0]-48)*128+(mem[t0][1]-48)*pc+(mem[t0][2]-48)*32+(mem[t0][3]-48)*16+(mem[t0][4]-48)*8+(mem[t0][5]-48)*4+(mem[t0][6]-48)*2+(mem[t0][7]-48)*1;
			}
		     }
		   else  if(op1==1||op1==3||op1==5||op1==15||op1==0)
		     {
			if(o2==0)
			{
				t0=64+(mem[pc][4]-48)*32+(mem[pc][5]-48)*16+(mem[pc][6]-48)*8+(mem[pc][7]-48)*4+o2;
				r0=(mem[t0][0]-48)*128+(mem[t0][1]-48)*pc+(mem[t0][2]-48)*32+(mem[t0][3]-48)*16+(mem[t0][4]-48)*8+(mem[t0][5]-48)*4+(mem[t0][6]-48)*2+(mem[t0][7]-48)*1;
			}
			if(o2==1)
			{
				t0=64+(mem[pc][4]-48)*32+(mem[pc][5]-48)*16+(mem[pc][6]-48)*8+(mem[pc][7]-48)*4+o2;
				r1=(mem[t0][0]-48)*128+(mem[t0][1]-48)*pc+(mem[t0][2]-48)*32+(mem[t0][3]-48)*16+(mem[t0][4]-48)*8+(mem[t0][5]-48)*4+(mem[t0][6]-48)*2+(mem[t0][7]-48)*1;
			}
			if(o2==2)
			{
				t0=64+(mem[pc][4]-48)*32+(mem[pc][5]-48)*16+(mem[pc][6]-48)*8+(mem[pc][7]-48)*4+o2;
				r2=(mem[t0][0]-48)*128+(mem[t0][1]-48)*pc+(mem[t0][2]-48)*32+(mem[t0][3]-48)*16+(mem[t0][4]-48)*8+(mem[t0][5]-48)*4+(mem[t0][6]-48)*2+(mem[t0][7]-48)*1;
				
			}
			if(o2==3)
			{
				t0=64+(mem[pc][4]-48)*32+(mem[pc][5]-48)*16+(mem[pc][6]-48)*8+(mem[pc][7]-48)*4+o2;
				r3=(mem[t0][0]-48)*128+(mem[t0][1]-48)*pc+(mem[t0][2]-48)*32+(mem[t0][3]-48)*16+(mem[t0][4]-48)*8+(mem[t0][5]-48)*4+(mem[t0][6]-48)*2+(mem[t0][7]-48)*1;
			}
		     }*/
			
		}	

/****************************************************************storing***************************************************************************************************************/		
		if(op==11 && opnext !=14)
		{

			o1=(mem[pc-1][4]-48)*2+(mem[pc-1][5]-48)*1;
			stadr=64+(mem[pc-1][6]-48)*32+(mem[pc-1][7]-48)*16+(mem[pc][4]-48)*8+(mem[pc][5]-48)*4+(mem[pc][6]-48)*2+(mem[pc][7]-48)*1;
			d0=r0;
			d1=r1;
			d2=r2;
			d3=r3;

			
			if(o1==0)
			{   
				
				   if(d0<0)
				{
					d0=256+d0;
					for(m=0;m<8;m++)
					{
						output[m]=d0%2+48;
						d0=d0/2;
								
					}
				}
				else
				{
					for(m=0;m<8;m++)
					{
						output[m]=d0%2+48;
						d0=d0/2;
								
					}
				}
					
				for(m=0;m<8;m++)
				{
					mem[stadr][m]=output[7-m];
				}
			}

			if(o1==1)
			{  
				   if(d1<0)
				{
					d1=256+d1;
					for(m=0;m<8;m++)
					{
						output[m]=d1%2+48;
						d1=d1/2;
								
					}
				}
				else
				{
					for(m=0;m<8;m++)
					{
						output[m]=d1%2+48;
						d1=d1/2;
								
					}
				}
					
				for(m=0;m<8;m++)
				{
					mem[stadr][m]=output[7-m];
				}
			}
			
			if(o1==2)
			{   
				   if(d2<0)
				{
					d2=256+r1;
					for(m=0;m<8;m++)
					{
						output[m]=d2%2+48;
						d2=d2/2;
								
					}
				}
				else
				{
					for(m=0;m<8;m++)
					{
						output[m]=d2%2+48;
						d2=d2/2;
								
					}
				}
					
				for(m=0;m<8;m++)
				{
					mem[stadr][m]=output[7-m];
				}
			}

			if(o1==3)
			{   
				   if(d3<0)
				{
					d3=256+d3;
					for(m=0;m<8;m++)
					{
						output[m]=d3%2+48;
						d3=d3/2;
								
					}
				}
				else
				{
					for(m=0;m<8;m++)
					{
						output[m]=d3%2+48;
						d3=r3/2;
								
					}
				}
					
				for(m=0;m<8;m++)
				{
					mem[stadr][m]=output[7-m];
				}
			}
			
			
		}

/****************************************************************************************************************************************/

		
		if(op==10 && opnext !=14)
		{
			if(operand1==0 && operand2==1)
			{
				r0=r1;
			}
			if(operand1==0 && operand2==2)
			{
				r0=r2;
			}
			if(operand1==0 && operand2==3)
			{
				r0=r3;
			}
			if(operand1==1 && operand2==0)
			{
				r1=r0;
			}
			if(operand1==1 && operand2==2)
			{
				r1=r2;
			}
			if(operand1==1 && operand2==3)
			{
				r1=r3;
			}
			if(operand1==2 && operand2==0)
			{
				r2=r0;
			}
			if(operand1==2 && operand2==1)
			{
				r2=r1;
			}
			if(operand1==2 && operand2==3)
			{
				r2=r3;
			}
			if(operand1==3 && operand2==0)
			{
				r3=r0;
			}
			if(operand1==3 && operand2==1)
			{
				r3=r1;
			}
			if(operand1==3 && operand2==2)
			{
				r3=r2;
			}
			
			
		}

		if(op==1 && opnext !=14)
		{
			if(operand1==0 && operand2==0)
			{
				r0=r0+r0;
			}
			if(operand1==0 && operand2==1)
			{
				r0=r0+r1;
			}
			if(operand1==0 && operand2==2)
			{
				r0=r0+r2;
			}
			if(operand1==0 && operand2==3)
			{
				r0=r0+r3;
			}
			if(operand1==1 && operand2==0)
			{
				r0=r1+r0;
			}
			if(operand1==1 && operand2==1)
			{
				r0=r1+r1;
			}
			if(operand1==1 && operand2==2)
			{
				r0=r1+r2;
			}
			if(operand1==1 && operand2==3)
			{
				r0=r1+r3;
			}
			if(operand1==2 && operand2==0)
			{
				r0=r2+r0;
			}
			if(operand1==2 && operand2==1)
			{
				r0=r2+r1;
			}
			if(operand1==2 && operand2==2)
			{
				r0=r2+r2;
			}
			if(operand1==2 && operand2==3)
			{
				r0=r2+r3;
			}
			if(operand1==3 && operand2==0)
			{
				r0=r3+r0;
			}
			if(operand1==3 && operand2==1)
			{
				r0=r3+r1;
			}
			if(operand1==3 && operand2==2)
			{
				r0=r3+r2;
			}
			if(operand1==3 && operand2==3)
			{
				r0=r3+r3;
			}
			
			
			
		}
		if(op==2 && opnext !=14)
		{
			if(operand1==0)
			{
				r0=r0+operand2;
			}			
			if(operand1==1)
			{
				r0=r1+operand2;
			}
			if(operand1==2)
			{
				r0=r2+operand2;
			}
			if(operand1==3)
			{
				r0=r3+operand2;
			}
		}
		
		if(op==3 && opnext !=14)
		{
			if(operand1==0 && operand2==0)
			{
				r0=r0-r0;
			}
			if(operand1==0 && operand2==1)
			{
				r0=r0-r1;
			}
			if(operand1==0 && operand2==2)
			{
				r0=r0-r2;
			}
			if(operand1==0 && operand2==3)
			{
				r0=r0-r3;
			}
			if(operand1==1 && operand2==0)
			{
				r0=r1-r0;
			}
			if(operand1==1 && operand2==1)
			{
				r0=r1-r1;
			}
			if(operand1==1 && operand2==2)
			{
				r0=r1-r2;
			}
			if(operand1==1 && operand2==3)
			{
				r0=r1-r3;
			}
			if(operand1==2 && operand2==0)
			{
				r0=r2-r0;
			}
			if(operand1==2 && operand2==1)
			{
				r0=r2-r1;
			}
			if(operand1==2 && operand2==2)
			{
				r0=r2-r2;
			}
			if(operand1==2 && operand2==3)
			{
				r0=r2-r3;
			}
			if(operand1==3 && operand2==0)
			{
				r0=r3-r0;
			}
			if(operand1==3 && operand2==1)
			{
				r0=r3-r1;
			}
			if(operand1==3 && operand2==2)
			{
				r0=r3-r2;
			}
			if(operand1==3 && operand2==3)
			{
				r0=r3-r3;
			}
			
			
			
		}
		
		if(op==4 && opnext !=14)
		{
			if(operand1==0)
			{
				r0=r0-operand2;
			}
			if(operand1==1)
			{
				r0=r1-operand2;
			}
			if(operand1==2)
			{
				r0=r2-operand2;
			}
			if(operand1==3)
			{
				r0=r3-operand2;
			}
		}
		
		if(op==5 && opnext !=14)
		{
			if(operand1==0 && operand2==0)
			{
				r0=r0*r0;
			}
			if(operand1==0 && operand2==1)
			{
				r0=r0*r1;
			}
			if(operand1==0 && operand2==2)
			{
				r0=r0*r2;
			}
			if(operand1==0 && operand2==3)
			{
				r0=r0*r3;
			}
			if(operand1==1 && operand2==0)
			{
				r0=r1*r0;
			}
			if(operand1==1 && operand2==1)
			{
				r0=r1*r1;
			}
			if(operand1==1 && operand2==2)
			{
				r0=r1*r2;
			}
			if(operand1==1 && operand2==3)
			{
				r0=r1*r3;
			}
			if(operand1==2 && operand2==0)
			{
				r0=r2*r0;
			}
			if(operand1==2 && operand2==1)
			{
				r0=r2*r1;
			}
			if(operand1==2 && operand2==2)
			{
				r0=r2*r2;
			}
			if(operand1==2 && operand2==3)
			{
				r0=r2*r3;
			}
			if(operand1==3 && operand2==0)
			{
				r0=r3*r0;
			}
			if(operand1==3 && operand2==1)
			{
				r0=r3*r1;
			}
			if(operand1==3 && operand2==2)
			{
				r0=r3*r2;
			}
			if(operand1==3 && operand2==3)
			{
				r0=r3*r3;
			}
			
			
		}
		
		
		
		if(op==13 && opnext !=14)
		{
			if(operand1==0)
			{
				r0=operand2;
			}
			if(operand1==1)
			{
				r1=operand2;
			}
			if(operand1==2)
			{
				r2=operand2;
			}
			if(operand1==3)
			{
				r3=operand2;
			}
		}
		
	
		
		
		
		if(op==14)
		{
			 
			jumpadr=(mem[pc-1][6]-48)*32+(mem[pc-1][7]-48)*16+(mem[pc][4]-48)*8+(mem[pc][5]-48)*4+(mem[pc][6]-48)*2+(mem[pc][7]-48)*1;
			looptimes=(mem[pc-1][0]-48)*32+(mem[pc-1][1]-48)*16+(mem[pc-1][2]-48)*8+(mem[pc-1][3]-48)*4+(mem[pc-1][4]-48)*2+(mem[pc-1][5]-48)*1;
			if(n < looptimes)
			{
				pc=jumpadr-1;
				n++;
				
			}
		}
		if(op==15 && opnext !=14)
		{
			
			//printadr=64+(mem[pc-1][6]-48)*32+(mem[pc-1][7]-48)*16+(mem[pc][4]-48)*8+(mem[pc][5]-48)*4+(mem[pc][6]-48)*2+(mem[pc][7]-48)*1;
			//for(m=0;m<8;m++)
			//{
				//printf("r0=%d\n",r0);
			//	printf("%c",mem[printadr][m]);
				
		//	}
			
			printf("%d ",r0);
			printf("\n");
			
		}
	
		if(op==8 && opnext !=14)
		{
			begzadr=(mem[pc-1][6]-48)*32+(mem[pc-1][7]-48)*16+(mem[pc][4]-48)*8+(mem[pc][5]-48)*4+(mem[pc][6]-48)*2+(mem[pc][7]-48)*1;
			condr=(mem[pc-1][4]-48)*2+(mem[pc-1][5]-48)*1;
			if(condr==0)
			{
				if(r0>=0)
				{
					pc=begzadr-1;
				}
			}
			if(condr==1)
			{
				if(r1>=0)
				{
					pc=begzadr-1;
				}
			}
			if(condr==2)
			{
				if(r2>=0)
				{
					pc=begzadr-1;
				}
			}
			if(condr==3)
			{
				if(r3>=0)
				{
					pc=begzadr-1;
				}
			}
		}

		if(op== 9 && opnext != 14)
		{
			jaladr=(mem[pc-1][6]-48)*32+(mem[pc-1][7]-48)*16+(mem[pc][4]-48)*8+(mem[pc][5]-48)*4+(mem[pc][6]-48)*2+(mem[pc][7]-48)*1;
			pc=jaladr-1;	
		}
		
		if(op==7 && opnext !=14)
		{
			o1=(mem[pc-1][4]-48)*2+(mem[pc-1][5]-48)*1;
			ifjadr=(mem[pc-1][6]-48)*32+(mem[pc-1][7]-48)*16+(mem[pc][4]-48)*8+(mem[pc][5]-48)*4+(mem[pc][6]-48)*2+(mem[pc][7]-48)*1;
			if(o1==0)
			{
				if(r0==0)
				{
					pc=ifjadr-1;
				}
			}
			if(o1==1)
			{
				if(r1==0)
				{
					pc=ifjadr-1;
				}
			}
			if(o1==2)
			{
				if(r2==0)
				{
					pc=ifjadr-1;
				}
			}		
			if(o1==3)
			{
				if(r3==0)
				{
					pc=ifjadr-1;
				}
			}	
		}
		
		
//printf("r0=%d\n",r0);			
	}

//printf("r0=%d\n",r0);
}


 
