/*!
 * @brief  This is a definition of RTSystemEditorPlugin.
 * @author Hisashi Ikari 
 * @file
 */
#ifndef CNOID_OPENRTM_PLUGIN_RTS_DIAGRAM_VIEW_H_INCLUDED
#define CNOID_OPENRTM_PLUGIN_RTS_DIAGRAM_VIEW_H_INCLUDED

#include <cnoid/View>
#include <cnoid/Dialog>
#include <QLineEdit>

using namespace cnoid;

namespace cnoid {
class RTSDiagramViewImpl;

class RTSDiagramView : public View {
Q_OBJECT

public:
	static void initializeClass(ExtensionManager* ext);
	static RTSDiagramView* instance();

	RTSDiagramView();
  virtual ~RTSDiagramView();

  void updateView();

public Q_SLOTS:
  void onRTSCompSelectionChange();

protected:
  virtual void onActivated() override;
  virtual void onDeactivated() override;
  virtual bool storeState(Archive& archive) override;
  virtual bool restoreState(const Archive& archive) override;
  
private :
	RTSDiagramViewImpl* impl;

};

class SettingDialog : public Dialog {
  Q_OBJECT
public:
  SettingDialog();

private Q_SLOTS:
  void oKClicked();
  void rejected();

private:
  QLineEdit* leName;
  QLineEdit* leVersion;
  QLineEdit* lePoling;
  QLineEdit* leHeartBeat;
};

}

#endif 
