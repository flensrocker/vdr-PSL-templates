/*
 * usingpsl.c: A plugin for the Video Disk Recorder
 *
 * See the README file for copyright information and how to reach the author.
 *
 * $Id$
 */

#include <vdr/plugin.h>
#include <vdr/psl-funcxy.h>


static const char *VERSION        = "0.0.1";
static const char *DESCRIPTION    = "Enter description for 'usingpsl' plugin";
static const char *MAINMENUENTRY  = "Usingpsl";

class cPluginUsingPsl : public cPlugin {
private:
  // Add any member variables or functions you may need here.
  PslFuncXy::cMyClass object;
public:
  cPluginUsingPsl(void);
  virtual ~cPluginUsingPsl();
  virtual const char *Version(void) { return VERSION; }
  virtual const char *Description(void) { return DESCRIPTION; }
  virtual const char *CommandLineHelp(void);
  virtual bool ProcessArgs(int argc, char *argv[]);
  virtual bool Initialize(void);
  virtual bool Start(void);
  virtual void Stop(void);
  virtual void Housekeeping(void);
  virtual void MainThreadHook(void);
  virtual cString Active(void);
  virtual time_t WakeupTime(void);
  virtual const char *MainMenuEntry(void) { return MAINMENUENTRY; }
  virtual cOsdObject *MainMenuAction(void);
  virtual cMenuSetupPage *SetupMenu(void);
  virtual bool SetupParse(const char *Name, const char *Value);
  virtual bool Service(const char *Id, void *Data = NULL);
  virtual const char **SVDRPHelpPages(void);
  virtual cString SVDRPCommand(const char *Command, const char *Option, int &ReplyCode);
  };

cPluginUsingPsl::cPluginUsingPsl(void)
{
  // Initialize any member variables here.
  // DON'T DO ANYTHING ELSE THAT MAY HAVE SIDE EFFECTS, REQUIRE GLOBAL
  // VDR OBJECTS TO EXIST OR PRODUCE ANY OUTPUT!
}

cPluginUsingPsl::~cPluginUsingPsl()
{
  // Clean up after yourself!
}

const char *cPluginUsingPsl::CommandLineHelp(void)
{
  // Return a string that describes all known command line options.
  return NULL;
}

bool cPluginUsingPsl::ProcessArgs(int argc, char *argv[])
{
  // Implement command line argument processing here if applicable.
  return true;
}

bool cPluginUsingPsl::Initialize(void)
{
  // Initialize any background activities the plugin shall perform.
  return true;
}

bool cPluginUsingPsl::Start(void)
{
  // Start any background activities the plugin shall perform.
  return true;
}

void cPluginUsingPsl::Stop(void)
{
  // Stop any background activities the plugin is performing.
}

void cPluginUsingPsl::Housekeeping(void)
{
  // Perform any cleanup or other regular tasks.
}

void cPluginUsingPsl::MainThreadHook(void)
{
  // Perform actions in the context of the main program thread.
  // WARNING: Use with great care - see PLUGINS.html!
}

cString cPluginUsingPsl::Active(void)
{
  // Return a message string if shutdown should be postponed
  return NULL;
}

time_t cPluginUsingPsl::WakeupTime(void)
{
  // Return custom wakeup time for shutdown script
  return 0;
}

cOsdObject *cPluginUsingPsl::MainMenuAction(void)
{
  // Perform the action when selected from the main VDR menu.
  return NULL;
}

cMenuSetupPage *cPluginUsingPsl::SetupMenu(void)
{
  // Return a setup menu in case the plugin supports one.
  return NULL;
}

bool cPluginUsingPsl::SetupParse(const char *Name, const char *Value)
{
  // Parse your own setup parameters and store their values.
  return false;
}

bool cPluginUsingPsl::Service(const char *Id, void *Data)
{
  // Handle custom service requests from other plugins
  return false;
}

const char **cPluginUsingPsl::SVDRPHelpPages(void)
{
  // Return help text for SVDRP commands this plugin implements
  return NULL;
}

cString cPluginUsingPsl::SVDRPCommand(const char *Command, const char *Option, int &ReplyCode)
{
  // Process SVDRP commands this plugin implements
  return NULL;
}

VDRPLUGINCREATOR(cPluginUsingPsl); // Don't touch this!
