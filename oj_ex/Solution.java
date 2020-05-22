
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Solution{
    public static boolean isPrimeNumber(int num)
    {
        if(num == 0 || num == 1)    return false;
        //定义一个标记变量
        boolean flag = true;        
        for(int i=2;i<num;i++) 
        {
            if(num%i == 0) 
            {
                flag=false;
                break;                    
            }
        }
        return flag;
    }
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        String s = in.nextLine();
        char[] chars = s.toCharArray();
        Map<Character, Integer> map = new HashMap<Character,Integer>();
        for(int i = 0;i < chars.length;i++) 
        {
		    //如果没有当前的key，就新建个节点放数据
		    if(!map.containsKey(chars[i])) 
			    map.put(chars[i], 1);
            else 
			    map.put(chars[i], map.get(chars[i])+1);//如果当前key存在，当前的value就+1
        }
        int max = 0;
        int min = 101;
        int num;
        for(int i = 0;i < chars.length;i++) 
        {
            num = map.get(chars[i]);
            if(num > max) 
                max = num;
            if(num < min)
                min = num;
        }
        int x = max - min; 
        if(isPrimeNumber(x))
        {
            System.out.println("Lucky Word");                                
            System.out.println(x);
        }
        else
        {
            System.out.println("No answer");                                
            System.out.println("0");   
        }
        in.close();
    }
}