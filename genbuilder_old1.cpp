// Generator builder
// This is the device that builds generators.
#include <filesystem> // C++17 specific feature.
#include <gtk/gtk.h>
#include <ifstream>
#include <libxml/parser.h>
#include <string>
#include <vector>

namespace fs = std::filesystem

// Add element to document.
// elementLabel is the label for the element, and
// listFile is the name of the list file.
void addElement(string elementToAdd, string elementLabel, string listFile)
{
	xmlNodePtr elementLabelNodePtr;
	xmlNodePtr elementNodePtr;
	elementLabelNodePtr = xmlNewNode(NULL, BAD_CAST "root");
	xmlNodeSetContent(n, BAD_CAST elementToAdd);
	xmlDocSetRootElement(doc, elementLabelNodePtr);
}

// Remove element from document.
void removeElement(xmlNodePtr elementToRemove)
{
	xmlUnlinkNode(elementToRemove);
	xmlFreeNode(elementToRemove);
}

int main(void)
{
	GtkWidget *window;
	GtkWidget *button;

	gtk_init();
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	g_signal_connect(window, "delete-event", G_CALLBACK(delete_event), NULL);
	g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
	
	// Linux specific code - change this if the code is ported to another platform!
	// Scroll through the lists directory and add files to the list.
	string temp;
	vector<string> fileNames;
	DIR *pdir = NULL; // Pointer to "lists" directory.
	struct dirent *pent = NULL;
	pdir = opendir ("."); // Will refer to the current directory.
	if (pdir == NULL)
	{
		cout << "Error! List file directory not initialized!" << endl;
	}
	
	int i = 0;
	while (pent = readdir (pdir) != NULL)
	{
		fileNames[i]
		i++;
	}
	// End Linux specific code.

	// Display the list of files.
		// CList
		// Vertical Scrollbar	

	xmlChar *xmlbuffer;
	int buffersize;

	// Create the XML document to store the generator.
	xmlDocPtr doc;
	doc = xmlNewDoc(BAD_CAST "1.0");	
	
	// Generate the menu for selecting a list file.
		

	return(0);
} 

