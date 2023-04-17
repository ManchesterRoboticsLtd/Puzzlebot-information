<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="20008000">
	<Item Name="My Computer" Type="My Computer">
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="Example_Robot_Simulation.vi" Type="VI" URL="../Example_Robot_Simulation.vi"/>
		<Item Name="Example_Simple_Plot.vi" Type="VI" URL="../Example_Simple_Plot.vi"/>
		<Item Name="Example_Sys_ID.vi" Type="VI" URL="../Example_Sys_ID.vi"/>
		<Item Name="PRBS_Generator.vi" Type="VI" URL="../PRBS_Generator.vi"/>
		<Item Name="PuzzlebotSim.vi" Type="VI" URL="../PuzzlebotSim.vi"/>
		<Item Name="System_ID.vi" Type="VI" URL="../System_ID.vi"/>
		<Item Name="Dependencies" Type="Dependencies">
			<Item Name="vi.lib" Type="Folder">
				<Item Name="Clear Errors.vi" Type="VI" URL="/&lt;vilib&gt;/Utility/error.llb/Clear Errors.vi"/>
				<Item Name="Draw Multiple Lines.vi" Type="VI" URL="/&lt;vilib&gt;/picture/picture.llb/Draw Multiple Lines.vi"/>
				<Item Name="FormatTime String.vi" Type="VI" URL="/&lt;vilib&gt;/express/express execution control/ElapsedTimeBlock.llb/FormatTime String.vi"/>
				<Item Name="Move Pen.vi" Type="VI" URL="/&lt;vilib&gt;/picture/picture.llb/Move Pen.vi"/>
				<Item Name="NI_AAL_Angle.lvlib" Type="Library" URL="/&lt;vilib&gt;/Analysis/NI_AAL_Angle.lvlib"/>
				<Item Name="NI_AALBase.lvlib" Type="Library" URL="/&lt;vilib&gt;/Analysis/NI_AALBase.lvlib"/>
				<Item Name="NI_AALPro.lvlib" Type="Library" URL="/&lt;vilib&gt;/Analysis/NI_AALPro.lvlib"/>
				<Item Name="NI_Matrix.lvlib" Type="Library" URL="/&lt;vilib&gt;/Analysis/Matrix/NI_Matrix.lvlib"/>
				<Item Name="NI_PtbyPt.lvlib" Type="Library" URL="/&lt;vilib&gt;/ptbypt/NI_PtbyPt.lvlib"/>
				<Item Name="Set Pen State.vi" Type="VI" URL="/&lt;vilib&gt;/picture/picture.llb/Set Pen State.vi"/>
				<Item Name="subElapsedTime.vi" Type="VI" URL="/&lt;vilib&gt;/express/express execution control/ElapsedTimeBlock.llb/subElapsedTime.vi"/>
			</Item>
			<Item Name="Checksum.vi" Type="VI" URL="../Dependencies/TcpCom/Checksum.vi"/>
			<Item Name="CloseCom.vi" Type="VI" URL="../Dependencies/TcpCom/CloseCom.vi"/>
			<Item Name="ComRobot.vi" Type="VI" URL="../Dependencies/TcpCom/ComRobot.vi"/>
			<Item Name="DCMotor.vi" Type="VI" URL="../Dependencies/DCMotor.vi"/>
			<Item Name="DrawPoly.vi" Type="VI" URL="../Dependencies/Graphics/DrawPoly.vi"/>
			<Item Name="Get Time.vi" Type="VI" URL="../Dependencies/TcpCom/Get Time.vi"/>
			<Item Name="GetTopic.vi" Type="VI" URL="../Dependencies/TcpCom/GetTopic.vi"/>
			<Item Name="InitCom.vi" Type="VI" URL="../Dependencies/TcpCom/InitCom.vi"/>
			<Item Name="lvanlys.dll" Type="Document" URL="/&lt;resource&gt;/lvanlys.dll"/>
			<Item Name="MessageFloat.ctl" Type="VI" URL="../Dependencies/TcpCom/MessageFloat.ctl"/>
			<Item Name="Odom.vi" Type="VI" URL="../Dependencies/Graphics/Odom.vi"/>
			<Item Name="OpenCom.vi" Type="VI" URL="../Dependencies/TcpCom/OpenCom.vi"/>
			<Item Name="ParseBuffer.vi" Type="VI" URL="../Dependencies/TcpCom/ParseBuffer.vi"/>
			<Item Name="Publish.vi" Type="VI" URL="../Dependencies/TcpCom/Publish.vi"/>
			<Item Name="ReadCom.vi" Type="VI" URL="../Dependencies/TcpCom/ReadCom.vi"/>
			<Item Name="RobotModel.vi" Type="VI" URL="../Dependencies/RobotModel.vi"/>
			<Item Name="RobotPlot.vi" Type="VI" URL="../Dependencies/Graphics/RobotPlot.vi"/>
			<Item Name="RobotSim.vi" Type="VI" URL="../Dependencies/RobotSim.vi"/>
			<Item Name="RobotVelocity.vi" Type="VI" URL="../Dependencies/Graphics/RobotVelocity.vi"/>
			<Item Name="SendMessage.vi" Type="VI" URL="../Dependencies/TcpCom/SendMessage.vi"/>
			<Item Name="Subscribe.vi" Type="VI" URL="../Dependencies/TcpCom/Subscribe.vi"/>
			<Item Name="UpdateTopic.vi" Type="VI" URL="../Dependencies/TcpCom/UpdateTopic.vi"/>
			<Item Name="WriteCom.vi" Type="VI" URL="../Dependencies/TcpCom/WriteCom.vi"/>
		</Item>
		<Item Name="Build Specifications" Type="Build"/>
	</Item>
</Project>
