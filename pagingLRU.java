import java.util.Scanner;

public class pagingLRU {

    static boolean searchElement(int n , int []frames)
    {
        for (int i : frames) {
            if (i == n) return true;
        }
        return false;
    }

    static void printFrames (int []frames)
    {
        for(int j = 0 ; j < frames.length ; j++){
            if(frames[j] == 0 ){
                System.out.println("Frame "+ j + " : _" );
                continue;
            }
            System.out.println("Frame "+ j + " : " + frames[j] );
        }
    }

    static boolean isEmpty (int [] frames)
    {
        for (int i : frames) {
            if ( i == 0) return true;
        }
        return false;
    }

    static int findIndex (int []frames ,int [] input ,int curr)
    {
        int[] diff = new int[frames.length];
        for (int j = 0 ; j < frames.length ; j++){
            for (int k = curr - 1 ; k >= 0 ; k--){
                if (frames [j] == input [k]){
                    diff[j] = curr - k; 
                    break;
                }
            }
        }
        int max = diff[0];
        int maxIndex = 0;
        for ( int i = 0; i<diff.length ; i++){
            if(max < diff[i]){
                max = diff[i];
                maxIndex = i;
            }
        }
        return maxIndex;
        
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] input = new int[100];
        int index = 0;
        while (true) {
            System.out.print("\nEnter Numbers in Sqeuence (-1 to exit) : ");
            int temp = sc.nextInt();
            if (temp == -1) {
                break;
            }
            input[index++] = temp;
        }

        System.out.print("\nEnter Number Of Frames : ");
        int fNum = sc.nextInt();

        int[] frames = new int[fNum];
        int frameIndex = 0;
        int indexLRU = 0;

        int hits = 0;
        int total = 0;

        for (int i = 0 ; i < index ; i++) {
            total++;
            if (searchElement(input[i], frames)){
                hits++;
                System.out.println("\n\nElement Found !!");
                printFrames(frames);
                continue;
            }
            System.out.println("\n\nPage Miss !!");
            if ( i < fNum || isEmpty(frames)){
                frames[frameIndex++] = input [i] ;
            }
            
            else{
                indexLRU = findIndex(frames, input, i);
                frames[indexLRU] = input [i] ;
            }
            printFrames(frames);
        } 

        System.out.println("\nHit Ratio : " + hits + "/" + total);
        float hitRatio = (float) hits / total;
        System.out.println("\nHit Ratio : " + hitRatio );
    }
}
