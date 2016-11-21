#ifndef QYOTUBESETTINGSDIALOG_H
#define QYOTUBESETTINGSDIALOG_H


#include "..\core\QVirtualSettingsTab.h"
#include "youtubecontroller.h"

class QIcon;
class QString;
class QVBoxLayout;
class QCheckBox;
class QPushButton;
class QLineEdit;
class QTextEdit;
class QGroupBox;
class QWidget;


class QYoutubeSettingsDialog:public QObject,public VirtualSettingsTab
{
    Q_OBJECT
public:
    QYoutubeSettingsDialog(QObject *parent = nullptr);
    virtual ~QYoutubeSettingsDialog(){}

    // QVirtualSettingsTab interface
public:
    virtual QWidget *createLayout(QWidget *parent,QSettings& settings);
    virtual void saveSettings(QSettings&settings);
    virtual void loadSettings(QSettings&settings);
    virtual QIcon getIcon();
    virtual QString getName();
    virtual QObject *getAdditionalInfo();

private:
    //tab control
    QVBoxLayout* layout;
    //controls
    QCheckBox *channelCheckBox;
    QPushButton *youtubeLoginWebsitePushButton;
     QPushButton *youtubeDeloginWebsitePushButton;
    QLineEdit *channelEdit;
    QLineEdit *aliasesEdit;
    QTextEdit *supportersListEdit;
    QTextEdit *blackListEdit;
    QCheckBox *removeBlackListUsersCheckBox;
    QGroupBox *groupBox;


    void retrieveO2Token();
private slots:
    void loginWebsiteButtonClicked();
    void deloginWebsiteButtonClicked();    
    void changeChannelAvailability(bool);



signals:

    void supportersListChanged( const QString & );
    void blackListChanged( const QString & );
    void removeBlackListUsersChanged( bool );
    void loginClicked();
    void deloginClicked();


};

#endif // QYOTUBESETTINGSDIALOG_H
