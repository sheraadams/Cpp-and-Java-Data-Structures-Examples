// Shera Adams
// shera.adams@snhu.edu
// January 26,2024
//
// Version: 2.0, This is an enhanced version of the CS250 slide show application project created for Southern New Hampshire University to 
// satisfy the data structures and algorithms category enhancement of CS499, Capstone class.
//
// The main purpose of SlideShow.java is to create a slide show of images and text descriptions using Java Swing to create the gui
// interface. This application is a wire frame and it is an early iteration in the development of a larger travel package booking system. 
//
// Changes: I have added the ArrayList structure in place of the conditional branching that previously controlled the slide show
// view to improve the maintainability, scalability, and improve the utilization of resources in the application. 
//
// Issues: none

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

public class SlideShow extends JFrame {
    // initialize the ArrayLists
    private ArrayList<String> slideImages;
    private ArrayList<String> slideText;
    
    // initialize the index variable
    private int currentSlideIndex;
   
    // initialize the panes
    private JPanel slidePane;
    private JPanel textPane;
    private JPanel buttonPane;
   
    // initialize the card components
    private CardLayout card;
    private CardLayout cardText;
   
    // initialize the buttons
    private JButton btnPrev;
    private JButton btnNext;
   
    // initialize the JLabel components
    private JLabel lblSlide;
    private JLabel lblTextArea;


    public SlideShow() throws HeadlessException {
        // call our initComponent() function
        this.initComponent();

        // call our ArrayList functions to populate the ArrayLists with the HTML code
        this.slideImages = createImages();
        this.slideText = createText();

        this.currentSlideIndex = 0; // initialize the index at zero

        // call the showSlide function to update the pane with the matching contents
        showSlide();       
    }

    // create the string ArrayList that stores the image HTML code that loads the images
    private ArrayList<String> createImages()  {
    	ArrayList<String> slideImages = new ArrayList<>();
    
    	// add the Costa Rica Image HTML
        slideImages.add("<html><body><img width= '800' height='500' src='" + 
        this.getClass().getResource("/resources/costarica.jpg") + "'  alt='Costa Rica Destination'> </body></html>");
    	
        // add the Sedona Image HTML
        slideImages.add("<html><body><img width= '800' height='500' src='" + 
        this.getClass().getResource("/resources/sedona.jpg") + "' alt='Sedona Destination'> </body></html>");
       
    	// add the Nepal Image HTML
        slideImages.add("<html><body><img width= '800' height='500' src='" + 
        this.getClass().getResource("/resources/nepal.jpg") + "' alt='Nepal Destination'> </body></html>");
      
        // add the Egypt Image HTML
        slideImages.add("<html><body><img width= '800' height='500' src='" + 
        this.getClass().getResource("/resources/egypt.jpg") + "' alt='Egypt Destination'> </body></html>");
      
        // add the Grand Canyon Image HTML
        slideImages.add("<html><body><img width= '800' height='500' src='" + 
        		this.getClass().getResource("/resources/grandcanyon.jpg") + "' alt='Grand Canyon Destination'> </body></html>");

        return slideImages;
    }

    // create the string ArrayList that stores the HTML code that formats the text
    private ArrayList<String> createText() {
    	ArrayList<String> slideText = new ArrayList<>();
    	
    	// add the Costa Rica Text HTML
        slideText.add("<html><body><font size='5'>1. Costa Rica</font> <br>Release toxins and find new inspiration "
                + "at the beautiful Ayurveda Yoga Wellness Retreats. </body></html>");
     
        // add the Sedona Text HTML
        slideText.add("<html><body><font size='5'>2. Sedona</font> <br>Visit some of the most famous detox centers "
                + "in the world and experience mind-body healing in the beautiful Sedona, Arizona.</body></html>");
     
        // add the Nepal Text HTML
        slideText.add("<html><body><font size='5'>3. Nepal</font> <br>Rejuvenate your mind and body and realign "
                + "yourself with yoga and meditation in the world class retreats of Nepal.</body></html>");
    
        // add the Egypt Text HTML
        slideText.add("<html><body><font size='5'>4. Egypt</font> <br>Immerse yourself in the history of ancient "
                + "civilizations as you realign body, mind, and spirit in breathtaking landscapes.</body></html>");
     
        // add the Grand Canyon Text HTML
        slideText.add("<html><body><font size='5'>5. Grand Canyon</font> <br>Relax in nature and find wellness and "
                + "adventure in the breathtaking views of the Grand Canyon.</body></html>");
        return slideText;
    }

    private void initComponent() {
        // create the card layout components
        this.card = new CardLayout();
        this.cardText = new CardLayout();
        
        // add the JPanel container for the slides
        this.slidePane = new JPanel();
        this.textPane = new JPanel();
       
        // set the color of the text box
        this.textPane.setBackground(Color.WHITE);
       
        // set the position of the text box
        this.textPane.setBounds(5, 470, 790, 50);
        this.textPane.setVisible(true);
        
        // create a button pane and buttons
        this.buttonPane = new JPanel();
        this.btnPrev = new JButton();
        this.btnNext = new JButton();
       
        // set the button pane to white
        this.buttonPane.setBackground(Color.WHITE);
        
        // create the slide area and the text area
        this.lblSlide = new JLabel();
        this.lblTextArea = new JLabel();
       
        // set the size of the GUI
        this.setSize(800, 600);
        this.setLocationRelativeTo(null);
       
        // set the title
        this.setTitle("Top Detox Destinations");
      
        // add horizontal and vertical padding
        this.getContentPane().setLayout(new BorderLayout(10, 50));
        this.setDefaultCloseOperation(3);
       
        // set the layout to the pane
        this.slidePane.setLayout(this.card);
        this.textPane.setLayout(this.cardText);
       
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
        buttonPane.add(this.btnPrev);
       
        /* Next Button */
        // add the text to the button
        this.btnNext.setText("   Next    ");
        // set a listener to the button that calls the goNext function
        this.btnNext.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                SlideShow.this.goNext();
            }
        });
        // add the button to the pane
        this.buttonPane.add(this.btnNext);
        
        // position the button pane at the bottom
        this.getContentPane().add(buttonPane, "South");
    }
    
    // cycle through the slides using modulo to keep within bounds, the currentSlideIndex defines the contents of the slide
    private void goPrevious() { 
        currentSlideIndex = (currentSlideIndex - 1 + slideImages.size()) % slideImages.size();
        showSlide();
    }

    // cycle through the slides using modulo to keep within bounds, the currentSlideIndex defines the contents of the slide
    private void goNext() {
        currentSlideIndex = (currentSlideIndex + 1) % slideImages.size();
        showSlide();
    }

    private void showSlide() {
        // clear the pane first
        this.slidePane.removeAll();
        this.textPane.removeAll();

        // create the JLabel if it doesn't exist
        if (this.lblSlide == null) {
            this.lblSlide = new JLabel();
            this.lblTextArea = new JLabel();
        }

        // get the current slide contents from the ArrayLists
        this.lblSlide.setText(this.slideImages.get(currentSlideIndex));
        this.lblTextArea.setText(this.slideText.get(currentSlideIndex));

        // add the contents to the pane
        this.slidePane.add(this.lblSlide, "card" + currentSlideIndex);
        this.textPane.add(this.lblTextArea, "cardText" + currentSlideIndex);

        // update the panes 
        this.slidePane.repaint();
        this.textPane.repaint();
    }
    
    public static void main(String[] args) {
        EventQueue.invokeLater(new Runnable() {
            public void run() {
                SlideShow ss = new SlideShow(); 
                ss.setVisible(true);
            }
        });
    }
}