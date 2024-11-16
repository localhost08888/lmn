import java.util.Scanner;

class InvalidDateException extends Exception {
    public InvalidDateException(String message) {
        super(message);
    }
}

class MyDate {
      int day;
      int month;
      int year;

    // Method to accept date input
    public void accept(int d, int m, int y) throws InvalidDateException
     {
        if (m < 1 || m > 12)
         {
            throw new InvalidDateException("Month must be between 1 and 12");
         }

        int[] daysInMonth = {31, isLeapYear(y) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (d < 1 || d > daysInMonth[m - 1])
         {
            throw new InvalidDateException("Day is not valid for the given month and year");
        }

        this.day = d;
        this.month = m;
        this.year = y;
    }

    // Method to display the date
    public void display() 
    {
        System.out.println("Date is valid: " + day + "/" + month + "/" + year);
    }

    // Method to check if a year is a leap year
    private boolean isLeapYear(int year)
     {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
}

public class setb1 
{
    public static void main(String[] args)
     {
        Scanner sc = new Scanner(System.in);
        MyDate date = new MyDate();

        System.out.println("Enter Date (dd mm yyyy):");
        int day = sc.nextInt();
        int month = sc.nextInt();
        int year = sc.nextInt();

        try 
        {
            date.accept(day, month, year);
            date.display();
        } 
        catch (InvalidDateException e) 
        {
            System.out.println("Invalid Date: " + e.getMessage());
        }
    }
}