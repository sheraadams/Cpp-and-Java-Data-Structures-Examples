// load the imports
import java.awt.BorderLayout;
import java.awt.CardLayout;
import java.awt.Color;
import java.awt.Component;
import java.awt.EventQueue;
import java.awt.FlowLayout;
import java.awt.HeadlessException;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class SlideShow extends JFrame {
	
    // initialize the panes
    private JPanel slidePane;
    private JPanel textPane;
    private JPanel buttonPane;

    // initialize the cart components
    private CardLayout card;
    private CardLayout cardText;

    // initialize the buttons
    private JButton btnPrev;
    private JButton btnNext;

    // initialize the jlabel components
    private JLabel lblSlide;
    private JLabel lblTextArea;

    public SlideShow() throws HeadlessException {
        // call the init funtion
        this.initComponent();
    }

    private void initComponent() {
        // create the card layout components
        this.card = new CardLayout();
        this.cardText = new CardLayout();
       
        // add the jpanel container for the slides    
        this.slidePane = new JPanel();
        this.textPane = new JPanel();
      
        // set the position of the text box   
        this.textPane.setBackground(Color.WHITE);
      
        // set the location of the text box
        this.textPane.setBounds(5, 470, 790, 50);
        this.textPane.setVisible(true);
       
        // create a button pane and buttons
        this.buttonPane = new JPanel();
        this.btnPrev = new JButton();
        this.btnNext = new JButton();

        // create the slide area and the text area    
        this.lblSlide = new JLabel();
        this.lblTextArea = new JLabel();

        // set the size of the gui    
        this.setSize(800, 600);
        this.setLocationRelativeTo((Component)null);
        
        // set the title of the window
        this.setTitle("Top Detox Destinations");

        // add horizontal and vertical padding
        this.getContentPane().setLayout(new BorderLayout(10, 50));
        this.setDefaultCloseOperation(3);
        
        // set the layout to the pane
        this.slidePane.setLayout(this.card);
        this.textPane.setLayout(this.cardText);

        // set the image and text to the value assigned by the condition 
        //for the matching value of i
        for(int i = 1; i <= 5; ++i) {
            
        	// create a new jlabel each time
            this.lblSlide = new JLabel();
            
            this.lblTextArea = new JLabel();
            // set the text to html string contents at the position of i 
            
            this.lblSlide.setText(this.getResizeIcon(i));
            // set the text to the html string contents at the position of i
            this.lblTextArea.setText(this.getTextDescription(i));
            // add the contents to the pane
            this.slidePane.add(this.lblSlide, "card" + i);
            this.textPane.add(this.lblTextArea, "cardText" + i);
        }
        
        // set the position of the panes
        this.getContentPane().add(this.slidePane, "Center");
        this.getContentPane().add(this.textPane, "South");
        
        // set the flow layout for the button pane and add padding
        this.buttonPane.setLayout(new FlowLayout(1, 20, 10));
        
        /* Previous Button */
        // set the text to the button
        this.btnPrev.setText("Previous"); 
        // set a listener to the button that calls the goPrevious function
        this.btnPrev.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                SlideShow.this.goPrevious();
            }
        });
        // add the button to the pane
        this.buttonPane.add(this.btnPrev);

        /* Next Button */
        // add the text to the button    
        this.btnNext.setText("    Next    ");
        // set a listener to the button that calls the goNext function    
        this.btnNext.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                SlideShow.this.goNext();
            }
        });
        // add the button to the pane
        this.buttonPane.add(this.btnNext);

        // position the button pane at the bottom
        this.getContentPane().add(this.buttonPane, "South");
    }
    
    // cycle through to the previous slide
    private void goPrevious() {
        this.card.previous(this.slidePane);
        this.cardText.previous(this.textPane);
    }
   
    // cycle through to the next slide
    private void goNext() {
        this.card.next(this.slidePane);
        this.cardText.next(this.textPane);
    }

    // function that returns the string HTML contents that load and format an image depending on the value of i
    private String getResizeIcon(int i) {
        String image = "";
        if (i == 1) {
            image = "<html><body><img width= '800' height='500' src='" + this.getClass().getResource("/resources/costarica.jpg") + "'</body></html>";
        } else if (i == 2) {
            image = "<html><body><img width= '800' height='500' src='" + this.getClass().getResource("/resources/sedona.jpg") + "'</body></html>";
        } else if (i == 3) {
            image = "<html><body><img width= '800' height='500' src='" + this.getClass().getResource("/resources/nepal.jpg") + "'</body></html>";
        } else if (i == 4) {
            image = "<html><body><img width= '800' height='500' src='" + this.getClass().getResource("/resources/egypt.jpg") + "'</body></html>";
        } else if (i == 5) {
            image = "<html><body><img width= '800' height='500' src='" + this.getClass().getResource("/resources/grandcanyon.jpg") + "'</body></html>";
        }

        return image;
    }

    // function that returns the string HTML contents that format and load the pane text depending on the value of i
    private String getTextDescription(int i) {
        String text = "";
        if (i == 1) {
            text = "<html><body><font size='5'>1. Costa Rica</font> <br>Release toxins and find new inspiration at the beautiful Ayurveda Yoga Wellness Retreats. </body></html>";
        } else if (i == 2) {
            text = "<html><body><font size='5'>2. Sedona</font> <br>Visit some of the most famous detox centers in the world and experience mind-body healing in the beautiful Sedona, Arizona.</body></html>";
        } else if (i == 3) {
            text = "<html><body><font size='5'>3. Nepal</font> <br>Rejuvenate your mind and body and realign yourself with yoga and meditation in the world class retreats of Nepal.</body></html>";
        } else if (i == 4) {
            text = "<html><body><font size='5'>4. Egypt</font> <br>Immerse yourself in the history of ancient civilizations as you realign body, mind, and spirit in breathtaking landscapes.</body></html>";
        } else if (i == 5) {
            text = "<html><body><font size='5'>5. Grand Canyon</font> <br>Relax in nature and find wellness and adventure in the breathtaking views of the Grand Canyon.</body></html>";
        }

        return text;
    }

    public static void main(String[] args) {   	
    	EventQueue.invokeLater(new Runnable() {
            public void run() {
                SlideShow ss = new SlideShow();
                // default close operation is to close the jframe on exit
                ss.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                ss.setVisible(true);
            }
        });
       
    }
}
