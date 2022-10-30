import java.util.Scanner;  
import java.lang.Math;
class Armstrong 
{
    public static void main(String args[])     
    {     
        int num,temp, digits=0, last, sum=0,power;   
        Scanner sc= new Scanner(System.in);  

        System.out.print("Enter the Number: ");  
        num=sc.nextInt(); 

        temp = num;
        while(temp>0)    
        {   
            temp = temp/10;   
            digits++;   
        }   

        temp = num;
        while(temp>0)   
        {     
            last = temp % 10;
            power = (int)(Math.pow(last, digits));
            sum = sum + power;   
            temp = temp/10;   
        }  

        if(num == sum) 
            System.out.println("Armstrong Number");
        else
            System.out.print("Not Armstrong Number");
    }
}

/*OUTPUT:
I: Enter the Number: 153
O: Armstrong Number
I: Enter the Number: 370
O: Armstrong Number
I: Enter the Number: 123
O: Not Armstrong Number
*/
