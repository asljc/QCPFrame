﻿/*
Author : Jamie.Tong
QQ      : 260271262
Data    : 2020-09-07
License: GPL v3.0
*/

#ifndef QPLUGIN1_H
#define QPLUGIN1_H

#include "../../QCPF_PluginModel/qcpf_systempluginmodel.h"

class MyClass
{
public:
    int Var1;
    QString Var2;
    double Var3;
};
Q_DECLARE_METATYPE(MyClass)

class PluginIO : public QCPF_SystemPluginModel
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID Plugin_Interface_iid FILE "QPlugin.json")
    Q_INTERFACES(Plugin_Interface)
public:
    PluginIO();
    ~PluginIO();

    void InitActionList(Plugin_Interface* plugin) Q_DECL_OVERRIDE;
    void InitWidgetList(Plugin_Interface* plugin) Q_DECL_OVERRIDE;

public:
    static PluginIO* getInstance();//静态获取实例

public slots:
    int slot_InputInfo(tagOutputInfo& info);

private:
    void Action_ShowSystemPluginManager(bool checkState);
    void Action_ShowRouteManager(bool checkState);
    void Action_CloseMainApplication(bool checkState);
    void Action_ShowAboutForm(bool checkState);
signals:
    void StartShowViewVersion();
};

#endif // QPLUGIN1_H
