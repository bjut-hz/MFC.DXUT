# MFC.DXUT
MFC.DXUT在DXUT框架上添加了新的接口，并编写了相应的开发模板代码，使得在MFC中方便使用DXUT框架，从而可以方便的
使用DXUT内包含的工具类
###DXUT
DXUT框架是建立在Direct3D API上的一个程序框架。建立了一个强大而且容易使用的Direct3D游戏开发示例、原型
和工具，通过封装D3D以及win32相关过程使其大大简化了windows以及Direct3D API的使用。
###MFC
微软基础类库（英语：Microsoft Foundation Classes，简称MFC）是一个微软公司提供的类库，以C++类的形式
封装了Windows API，并且包含一个应用程序框架，以减少应用程序开发人员的工作量。其中包含的类包含大
量Windows句柄封装类和很多Windows的内建控件和组件的封装类。

#使用说明
需要把[核心文件](https://github.com/bjut-hz/MFC.DXUT/tree/master/MFC.DXUT/DXUT/Core)去替换DXUT框架中原有的
文件，替换完成后，建立基于对话框的MFC程序，依照模板代码DXUTD3D11.h以及DXUTD3D11.cpp重新编写适用于自己需要代码。
具体可参照教程[MFC中使用DXUT](#)

#开发进度
目前已对D3D11的DXUT框架进行了适配
