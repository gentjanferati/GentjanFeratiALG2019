import java.io.*;
import java.util.*;

import org.jsoup.*;
import org.jsoup.nodes.*;
import org.jsoup.select.*;

public class WebCrawler {

	private static String path;
    private static int thellesia_max;

	private static HashSet<String> hs;

	public static void merrFaqet(String url, int thellesia) throws IOException {
		if(url==null || url=="") {
			return;
		}
		
		if( !hs.contains(url) && thellesia <= thellesia_max) {
			try {
				hs.add(url);
				
				PrintWriter pw = new PrintWriter(new FileWriter(path,true));
				pw.println("Thellesia: "+thellesia+" | Url: "+url);
				pw.close();
				Document doc = Jsoup.connect(url).get();
                Elements linket = doc.select("a[href]");
                
                thellesia += 1;
                for(Element faqe: linket) {
                	merrFaqet(faqe.attr("abs:href"),thellesia);
                }
                
			} catch (IOException ex) {
                System.out.println("Error: " + ex.getMessage());
			}
		}
	}
	
	public static void main(String[] args) throws IOException {
		if(args.length<3) {
			System.out.println("Mungojn argumentat!");
			return;
		}
		String url = args[0];
		thellesia_max = Integer.parseInt(args[1]);
		path = args[2];
		hs = new HashSet<String>();
		
		PrintWriter pw = new PrintWriter(new File(path));
		pw.close();
		merrFaqet(url,0);
	}
}
