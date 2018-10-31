class Armstrong
{
    public static void main(String args[])
    {
        int num = Integer.parseInt(args[0]);
        int n = num;
        int check=0,remainder;
        while(num > 0)
        {
            remainder = num % 10;
            check = check + (int)Math.pow(remainder,3);
            num = num / 10;
        }
        if(check != n)
            System.out.println(n+" - not Armstrong Number");
        else
            System.out.println(n+" - Armstrong Number");
    }
}
