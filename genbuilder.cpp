// Generator builder
// This is the device that builds generators.
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>
#include <gtk/gtk.h>
#include <ifstream>
#include <libxml/parser.h>
#include <string>
#include <vector>

namespace fs = boost::filesystem;
using namespace std;

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

// GTK
void activate(GtkApplication *app, gpointer user_data)
{
	GtkWidget *window;
	GtkWidget *button;
	GtkWidget *textTagTable;

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Generator Editor");
	gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);
	
	g_signal_connect(window, "delete-event", G_CALLBACK(delete_event), NULL);
	g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
	
	
}

int main(void)
{
	gtk_init();

	// Build a list of directories.
	string dirPath = "/ListFiles"; // Path to directory
	fs::path p(dirPath);
	vector<string> fileNames = "";
	
	if(fs::is_directory(p))
	int i = 0;
	for (auto & p : fs::make_iterator_range(fs::directory_iterator(p), {}))	
	{
		fileNames[i] = fs::entry;
		i++;
	}

	// Display the list of files.
		// CList
		// Vertical Scrollbar	
	fileListBuffer = gtk_text_buffer_new (GTKTextTagTable *table);
	fileListWindow = gtk_text_view_new_with_buffer (fileListBuffer);
	
	fileListScrollbar = gtk_scrollbar_new(vertical);
	i
	xmlChar *xmlbuffer;
	int buffersize;

	// Create the XML document to store the generator.
	xmlDocPtr doc;
	doc = xmlNewDoc(BAD_CAST "1.0");	
	
	// Generate the menu for selecting a list file.
		

	return(0);
} 

