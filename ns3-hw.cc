/*
本链路为19组P2P链路加上三个CSMA内节点组成共41个节点
本程序实现构架，以及各节点获取网络内arp地址的作用，对丢包等分析未掌握，因此未实现
本程序仿照：
ns-3.29/src/netanim/examples/dumbbell-animation.cc
ns-3.29/examples/tutorial/second.cc
使用了全局路由管理器，根据节点产生的链路通告为每个节点建立路由表，开启了网络嗅探器


王煦焱 控制工程18-3  2111803241 
*/
#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/csma-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/applications-module.h"
#include "ns3/ipv4-global-routing-helper.h"
#include "ns3/netanim-module.h"
using namespace ns3;
NS_LOG_COMPONENT_DEFINE("SecondScriptExample");//声明一个叫SecondScriptExample的日志构件，通过引用SecondScriptExample这个名字的操作
int main(int argc, char *argv[])
{
	Config::SetDefault("ns3::OnOffApplication::PacketSize", UintegerValue(200));
	Config::SetDefault("ns3::OnOffApplication::DataRate", StringValue("14kb/s"));
	std::string animFile = "test6.xml";//设定生成的xml文件名为wxy
	bool verbose = true;//打开日志记录
	uint32_t nCsma = 3;//设定csma内的数量为3

	CommandLine cmd;//命令行操作
	cmd.AddValue("nCsma", "Number of \"extra\" CSMA nodes/devices", nCsma);
	cmd.AddValue("verbose", "Tell echo applications to log if true", verbose);//命令行参数设置是否开启日志
	cmd.AddValue("animFile", "File Name for Animation Output", animFile);//申明拓展图输出的文件姓名
	cmd.Parse(argc, argv);

	if (verbose)//如果设定开启
	{
		LogComponentEnable("UdpEchoClientApplication", LOG_LEVEL_INFO);
		LogComponentEnable("UdpEchoServerApplication", LOG_LEVEL_INFO);
	}

	nCsma = nCsma == 0 ? 1 : nCsma;
	//p2p
	NodeContainer p2pNodes;//创建19个使用P2P链路链接的2个node
	p2pNodes.Create(2);
	NodeContainer p2pNodes2;//copy
	p2pNodes2.Create(2);
	NodeContainer p2pNodes3;//copy
	p2pNodes3.Create(2);
	NodeContainer p2pNodes4;//copy
	p2pNodes4.Create(2);
	NodeContainer p2pNodes5;//copy
	p2pNodes5.Create(2);
	NodeContainer p2pNodes6;//copy
	p2pNodes6.Create(2);
	NodeContainer p2pNodes7;//copy
	p2pNodes7.Create(2);
	NodeContainer p2pNodes8;//copy
	p2pNodes8.Create(2);
	NodeContainer p2pNodes9;//copy
	p2pNodes9.Create(2);
	NodeContainer p2pNodes10;//copy
	p2pNodes10.Create(2);
	NodeContainer p2pNodes11;
	p2pNodes11.Create(2);
	NodeContainer p2pNodes12;//copy
	p2pNodes12.Create(2);
	NodeContainer p2pNodes13;//copy
	p2pNodes13.Create(2);
	NodeContainer p2pNodes14;//copy
	p2pNodes14.Create(2);
	NodeContainer p2pNodes15;//copy
	p2pNodes15.Create(2);
	NodeContainer p2pNodes16;//copy
	p2pNodes16.Create(2);
	NodeContainer p2pNodes17;//copy
	p2pNodes17.Create(2);
	NodeContainer p2pNodes18;//copy
	p2pNodes18.Create(2);
	NodeContainer p2pNodes19;//copy
	p2pNodes19.Create(2);

	//csma网络中添加P2P的第一个节点
	NodeContainer csmaNodes;
	csmaNodes.Add(p2pNodes.Get(1));
	csmaNodes.Add(p2pNodes2.Get(1));
	csmaNodes.Add(p2pNodes3.Get(1));
	csmaNodes.Add(p2pNodes4.Get(1));
	csmaNodes.Add(p2pNodes5.Get(1));
	csmaNodes.Add(p2pNodes6.Get(1));
	csmaNodes.Add(p2pNodes7.Get(1));
	csmaNodes.Add(p2pNodes8.Get(1));
	csmaNodes.Add(p2pNodes9.Get(1));
	csmaNodes.Add(p2pNodes10.Get(1));
	csmaNodes.Add(p2pNodes11.Get(1));
	csmaNodes.Add(p2pNodes12.Get(1));
	csmaNodes.Add(p2pNodes13.Get(1));
	csmaNodes.Add(p2pNodes14.Get(1));
	csmaNodes.Add(p2pNodes15.Get(1));
	csmaNodes.Add(p2pNodes16.Get(1));
	csmaNodes.Add(p2pNodes17.Get(1));
	csmaNodes.Add(p2pNodes18.Get(1));
	csmaNodes.Add(p2pNodes19.Get(1));
	csmaNodes.Create(nCsma);



	PointToPointHelper pointToPoint;//设置基本的P2P参数：带宽以及延时，并分配至各个P2P节点
	pointToPoint.SetDeviceAttribute("DataRate", StringValue("5Mbps"));
	pointToPoint.SetChannelAttribute("Delay", StringValue("2ms"));

	NetDeviceContainer p2pDevices;
	p2pDevices = pointToPoint.Install(p2pNodes);

	NetDeviceContainer p2pDevices2;
	p2pDevices2 = pointToPoint.Install(p2pNodes2);

	NetDeviceContainer p2pDevices3;
	p2pDevices3 = pointToPoint.Install(p2pNodes3);

	NetDeviceContainer p2pDevices4;
	p2pDevices4 = pointToPoint.Install(p2pNodes4);

	NetDeviceContainer p2pDevices5;
	p2pDevices5 = pointToPoint.Install(p2pNodes5);

	NetDeviceContainer p2pDevices6;
	p2pDevices6 = pointToPoint.Install(p2pNodes6);

	NetDeviceContainer p2pDevices7;
	p2pDevices7 = pointToPoint.Install(p2pNodes7);

	NetDeviceContainer p2pDevices8;
	p2pDevices8 = pointToPoint.Install(p2pNodes8);

	NetDeviceContainer p2pDevices9;
	p2pDevices9 = pointToPoint.Install(p2pNodes9);

	NetDeviceContainer p2pDevices10;
	p2pDevices10 = pointToPoint.Install(p2pNodes10);

	NetDeviceContainer p2pDevices11;
	p2pDevices11 = pointToPoint.Install(p2pNodes11);

	NetDeviceContainer p2pDevices12;
	p2pDevices12 = pointToPoint.Install(p2pNodes12);

	NetDeviceContainer p2pDevices13;
	p2pDevices13 = pointToPoint.Install(p2pNodes13);

	NetDeviceContainer p2pDevices14;
	p2pDevices14 = pointToPoint.Install(p2pNodes14);

	NetDeviceContainer p2pDevices15;
	p2pDevices15 = pointToPoint.Install(p2pNodes15);

	NetDeviceContainer p2pDevices16;
	p2pDevices16 = pointToPoint.Install(p2pNodes16);

	NetDeviceContainer p2pDevices17;
	p2pDevices17 = pointToPoint.Install(p2pNodes17);

	NetDeviceContainer p2pDevices18;
	p2pDevices18 = pointToPoint.Install(p2pNodes18);

	NetDeviceContainer p2pDevices19;
	p2pDevices19 = pointToPoint.Install(p2pNodes19);





	//设置基本的csma参数：带宽以及延时。并分配给csma网络
	CsmaHelper csma;
	csma.SetChannelAttribute("DataRate", StringValue("100Mbps"));
	csma.SetChannelAttribute("Delay", TimeValue(NanoSeconds(6560)));

	NetDeviceContainer csmaDevices;
	csmaDevices = csma.Install(csmaNodes);

	InternetStackHelper stack;//协议安装
	stack.Install(p2pNodes.Get(0));
	stack.Install(p2pNodes2.Get(0));
	stack.Install(p2pNodes3.Get(0));
	stack.Install(p2pNodes4.Get(0));
	stack.Install(p2pNodes5.Get(0));
	stack.Install(p2pNodes6.Get(0));
	stack.Install(p2pNodes7.Get(0));
	stack.Install(p2pNodes8.Get(0));
	stack.Install(p2pNodes9.Get(0));
	stack.Install(p2pNodes10.Get(0));
	stack.Install(p2pNodes11.Get(0));
	stack.Install(p2pNodes12.Get(0));
	stack.Install(p2pNodes13.Get(0));
	stack.Install(p2pNodes14.Get(0));
	stack.Install(p2pNodes15.Get(0));
	stack.Install(p2pNodes16.Get(0));
	stack.Install(p2pNodes17.Get(0));
	stack.Install(p2pNodes18.Get(0));
	stack.Install(p2pNodes19.Get(0));
	stack.Install(csmaNodes);

	Ipv4AddressHelper address;//各个p2p网络的IP地址段
	address.SetBase("10.1.1.0", "255.255.255.0");
	Ipv4InterfaceContainer p2pInterfaces;
	p2pInterfaces = address.Assign(p2pDevices);

	address.SetBase("10.2.1.0", "255.255.255.0");
	Ipv4InterfaceContainer p2pInterfaces2;
	p2pInterfaces2 = address.Assign(p2pDevices2);

	address.SetBase("10.3.1.0", "255.255.255.0");
	Ipv4InterfaceContainer p2pInterfaces3;
	p2pInterfaces3 = address.Assign(p2pDevices3);

	address.SetBase("10.4.1.0", "255.255.255.0");
	Ipv4InterfaceContainer p2pInterfaces4;
	p2pInterfaces4 = address.Assign(p2pDevices4);

	address.SetBase("10.5.1.0", "255.255.255.0");
	Ipv4InterfaceContainer p2pInterfaces5;
	p2pInterfaces5 = address.Assign(p2pDevices5);

	address.SetBase("10.6.1.0", "255.255.255.0");
	Ipv4InterfaceContainer p2pInterfaces6;
	p2pInterfaces6 = address.Assign(p2pDevices6);

	address.SetBase("10.7.1.0", "255.255.255.0");
	Ipv4InterfaceContainer p2pInterfaces7;
	p2pInterfaces7 = address.Assign(p2pDevices7);

	address.SetBase("10.8.1.0", "255.255.255.0");
	Ipv4InterfaceContainer p2pInterfaces8;
	p2pInterfaces8 = address.Assign(p2pDevices8);

	address.SetBase("10.9.1.0", "255.255.255.0");
	Ipv4InterfaceContainer p2pInterfaces9;
	p2pInterfaces9 = address.Assign(p2pDevices9);

	address.SetBase("10.10.1.0", "255.255.255.0");
	Ipv4InterfaceContainer p2pInterfaces10;
	p2pInterfaces10 = address.Assign(p2pDevices10);

	address.SetBase("10.11.1.0", "255.255.255.0");
	Ipv4InterfaceContainer p2pInterfaces11;
	p2pInterfaces11 = address.Assign(p2pDevices11);

	address.SetBase("10.12.1.0", "255.255.255.0");
	Ipv4InterfaceContainer p2pInterfaces12;
	p2pInterfaces12 = address.Assign(p2pDevices12);

	address.SetBase("10.13.1.0", "255.255.255.0");
	Ipv4InterfaceContainer p2pInterfaces13;
	p2pInterfaces13 = address.Assign(p2pDevices13);

	address.SetBase("10.14.1.0", "255.255.255.0");
	Ipv4InterfaceContainer p2pInterfaces14;
	p2pInterfaces14 = address.Assign(p2pDevices14);

	address.SetBase("10.15.1.0", "255.255.255.0");
	Ipv4InterfaceContainer p2pInterfaces15;
	p2pInterfaces15 = address.Assign(p2pDevices15);

	address.SetBase("10.16.1.0", "255.255.255.0");
	Ipv4InterfaceContainer p2pInterfaces16;
	p2pInterfaces16 = address.Assign(p2pDevices16);

	address.SetBase("10.17.1.0", "255.255.255.0");
	Ipv4InterfaceContainer p2pInterfaces17;
	p2pInterfaces17 = address.Assign(p2pDevices17);

	address.SetBase("10.18.1.0", "255.255.255.0");
	Ipv4InterfaceContainer p2pInterfaces18;
	p2pInterfaces18 = address.Assign(p2pDevices18);

	address.SetBase("10.19.1.0", "255.255.255.0");
	Ipv4InterfaceContainer p2pInterfaces19;
	p2pInterfaces19 = address.Assign(p2pDevices19);

	address.SetBase("10.1.2.0", "255.255.255.0");//csma的IP地址段
	Ipv4InterfaceContainer csmaInterfaces;
	csmaInterfaces = address.Assign(csmaDevices);
	

	UdpEchoServerHelper echoServer(9);//协议安装在端口9

	ApplicationContainer serverApps = echoServer.Install(csmaNodes.Get(0));//将Server服务安装在CSMA网段的最后一个节点上
	serverApps.Start(Seconds(1.0));
	serverApps.Stop(Seconds(10.0));

	UdpEchoClientHelper echoClient(csmaInterfaces.GetAddress(0), 9);
	echoClient.SetAttribute("MaxPackets", UintegerValue(1));
	echoClient.SetAttribute("Interval", TimeValue(Seconds(1.0)));
	echoClient.SetAttribute("PacketSize", UintegerValue(1024));


	//将Client服务安装在P2P网段的第一个节点上
	ApplicationContainer clientApps = echoClient.Install(p2pNodes.Get(0));
	clientApps.Start(Seconds(2.0));
	clientApps.Stop(Seconds(10.0));

	ApplicationContainer clientApps2 = echoClient.Install(p2pNodes2.Get(0));
	clientApps2.Start(Seconds(2.0));
	clientApps2.Stop(Seconds(10.0));

	ApplicationContainer clientApps3 = echoClient.Install(p2pNodes3.Get(0));
	clientApps3.Start(Seconds(2.0));
	clientApps3.Stop(Seconds(10.0));

	Ipv4GlobalRoutingHelper::PopulateRoutingTables(); //全局路由管理器根据节点产生的链路通告为每个节点建立路由表

	pointToPoint.EnablePcapAll("wxy");//开启P2PHelper类对象的pcap
	csma.EnablePcap("wxy", csmaDevices.Get(1), true);//开启csmaHelper类对象的pcap,使用csma网段第二个节点进行sniff，True开启混杂模式

	AnimationInterface anim(animFile);//输出
	Simulator::Run();
	Simulator::Destroy();
	return 0;
}
