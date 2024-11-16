
public class setb2 
{
    int num;
  
    setb2(int n)
    {
       this.num=n;
    }

    public boolean isnegative()
    {
        if(num<0)
            return true;
        else
            return false;
    }
    public boolean ispositive()
    {
        if(num>0)
            return true;
        else
            return false;
    }
    public boolean iszero()
    {
        if(num==0)
            return true;
        else
            return false;
    }
    public boolean isodd()
    {
        if(num%2!=0)
            return true;
        else
             return false;
    }
    public boolean iseven()
    {
        if(num%2==0)
            return true;
        else
            return false;
    }
//---------------------------------------------
public static void main(String[] args)
{
    //Scanner sc=new Scanner(System.in);
    //System.out.println("enter number");      
    //int num=sc.nextInt();

    setb2 m=new setb2(5);//num  //from parameterized constructor already psssing value  by command line argument
    if(m.isnegative())
     System.out.println("Number is Negative");

    if(m.ispositive())
     System.out.println("Number is Positive");

    if(m.iseven())
     System.out.println("Number is Even");

    if(m.isodd())
     System.out.println("Number is Odd");

    if(m.iszero())
     System.out.println("Number is Zero");
     
   }
}


