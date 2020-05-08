
import java.lang.*;
import java.io.*;

class PSHOT
{
    public static void main (String[] args)
    {
        try {
            BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
            if(br!=null) {
                String s=br.readLine(),score;
                int t=Integer.parseInt(s),aScore=0,bScore=0,aLeft=0,bLeft=0,attempt;
                while(t!=0) {
                    aScore=bScore=aLeft=bLeft=attempt=0;
                    s=br.readLine();
                    int n=Integer.parseInt(s); //Number of game
                    aLeft=bLeft=n;
                    score=br.readLine();
                    for(int i=0;i<score.length();i++)
                    {
                        if(i%2==0)
                        {
                            if(score.charAt(i)=='1')
                            {
                                aLeft--;
                                aScore++;
                            }
                            else
                                aLeft--;
                            if((aScore>(bScore+bLeft)) || (bScore>(aScore+aLeft)) ) {
                                //A is winner
                                attempt=i+1;
                                break;
                            }
                        }
                        else {

                            if(score.charAt(i)=='1')
                            {
                                bLeft--;
                                bScore++;
                            }
                            else {
                                bLeft--;

                            }
                        }
                        if((bScore>(aScore+aLeft)) || (aScore>(bScore+bLeft))) {
                            attempt=i+1;
                            break;
                        }

                    }

                    if(attempt==0)
                        attempt=2*n;
                    System.out.println(attempt);
                    t--;
                }
            }
        }catch(Exception e) {
            e.printStackTrace();

        }
    }
}
