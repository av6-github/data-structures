import java.util.Scanner;

public class pagingFIFO {

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
            
            frames[frameIndex++] = input [i] ;
            System.out.println("\n\nPage Miss !!");
            if(frameIndex == fNum){
                frameIndex = 0 ;
            }
            printFrames(frames);
        } 

        System.out.println("\nHit Ratio : " + hits + "/" + total);
        float hitRatio = (float) hits / total;
        System.out.println("\nHit Ratio : " + hitRatio );
    }
}
