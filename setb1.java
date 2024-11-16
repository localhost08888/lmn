import java.text.SimpleDateFormat;
import java.util.Date;
public class setb1
{
 public static void main(String[] arg)
    {
        Date currdate=new Date();// obj of Date to accept current date and time
       
        SimpleDateFormat format1=new SimpleDateFormat("dd/MM/yyyy"); // Format 1: "31/07/2015"
        System.out.println("current date is:"+format1.format(currdate));
        
        SimpleDateFormat format2=new SimpleDateFormat("dd-MM-yyyy");// Format 2: "07-31-2015"
        System.out.println("current date is:"+format2.format(currdate));

        SimpleDateFormat format3=new SimpleDateFormat(" EEEE MM dd yyyy"); // Format 3: "Friday July 31 2015"
        System.out.println("current date is:"+format3.format(currdate));

        SimpleDateFormat format4=new SimpleDateFormat(" EEEE MM dd HH:mm:ss z yyyy");  // Format 4: "Fri July 31 16:25:56 IST 2015"
        System.out.println("current date and time is:"+format4.format(currdate));
 
        SimpleDateFormat format5=new SimpleDateFormat("dd/MM/yy HH:mm:ss a Z");  // Format 5: "31/07/15 16:25:56 PM +0530"
        System.out.println("current date and time  is:"+format5.format(currdate));

        SimpleDateFormat format6=new SimpleDateFormat(" HH:mm:ss ");  // Format 6: "16:25:56"
        System.out.println("current time  is:"+format6.format(currdate));

        SimpleDateFormat format7=new SimpleDateFormat("w"); 
        System.out.println("week of year:"+format7.format(currdate));

        SimpleDateFormat format8=new SimpleDateFormat("W"); 
        System.out.println("week of month:"+format8.format(currdate));

        SimpleDateFormat format9=new SimpleDateFormat("D"); 
        System.out.println("current day of year:"+format9.format(currdate));
    }
}
