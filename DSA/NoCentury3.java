/* Save this in a file called Main.java to compile and test it */

/* Do not add a package declaration */
import java.util.*;
import java.io.*;

/* You may add any imports here, if you wish, but only from the 
   standard library */

class Score {
    private String country;
    private int score;
    public Score(String c, int s) {
        country = c;
        score = s;
    }

    public String getCountry() {return country;}
    public void unsetCountry() {country = "";}
    public int getScore() {return score;}
}

public class Main {
    /**
     * Read `country: score` pairs from infile and return a list of pairs
     * Stop when `infile` reaches EOF
     */
    public static ArrayList<Score> readScores(Scanner infile) {
        ArrayList<Score> scores = new ArrayList<>();
        while(infile.hasNextLine()) {
            String line = infile.nextLine().trim();
            if(!line.isEmpty()) {
                String[] fields = line.split(":");
                Score score = new Score(fields[0].trim(),
                                        Integer.parseInt(fields[1].trim()));
                scores.add(score);
            }
        }
        return scores;
    }

    public static int noCenturyCountryCount(ArrayList<Score> scores) {
        int noCenturyCount = 0;
        for(int i=0; i<scores.size(); i++) {
            String country = scores.get(i).getCountry();
            if (country.isEmpty())
                // This country was already processed earlier
                continue;

            int centuries = 0;
            for(int j=i; j<scores.size(); j++) {
                if (scores.get(j).getCountry().equals(country) &&  scores.get(j).getScore() >= 100) {
                    centuries++;
                }
                // disable checking of this same country again
                scores.get(j).unsetCountry();
            }
            if (centuries == 0) {
                noCenturyCount++;
            }
        }
        return noCenturyCount;
    }

    public static void main (String[] args) {
        Scanner infile = new Scanner(System.in);
        ArrayList<Score> scores = Main.readScores(infile);
        int noCenturyCount = Main.noCenturyCountryCount(scores);
        System.out.println(noCenturyCount);
    }
}



https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118817/offering/1382241?leftPanelTab=0
