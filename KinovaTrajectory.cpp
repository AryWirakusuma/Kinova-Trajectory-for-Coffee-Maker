
//
// Created by ary, ihsan, faadilah, rian
//
#define UNICODE
#include "KinovaTypes.h"
#include <iostream>
#include <windows.h>
#include "CommunicationLayer.h"
#include "CommandLayer.h"
#include <conio.h>
#include<dos.h>

using namespace std;

HINSTANCE commandLayer_handle;
int(*MyInitAPI)();
int(*MyCloseAPI)();
int(*MySendBasicTrajectory)(TrajectoryPoint command);
int(*MyGetDevices)(KinovaDevice devices[MAX_KINOVA_DEVICE], int &result);
int(*MySetActiveDevice)(KinovaDevice device);
int(*MyMoveHome)();
int(*MyInitFingers)();
int(*MyGetCartesianCommand)(CartesianPosition &);

int main(){
    CartesianPosition currentCommand;
    int programResult = 0;
    int nilai ;
    int n ;

    commandLayer_handle = LoadLibraryA("CommandLayerWindows.dll");

    MyInitAPI = (int(*)()) GetProcAddress(commandLayer_handle, "InitAPI");
    MyCloseAPI = (int(*)()) GetProcAddress(commandLayer_handle, "CloseAPI");
    MyMoveHome = (int(*)()) GetProcAddress(commandLayer_handle, "MoveHome");
    MyInitFingers = (int(*)()) GetProcAddress(commandLayer_handle, "InitFingers");
    MyGetDevices = (int(*)(KinovaDevice devices[MAX_KINOVA_DEVICE],
                           int &result)) GetProcAddress(commandLayer_handle, "GetDevices");
    MySetActiveDevice = (int(*)(KinovaDevice devices)) GetProcAddress(commandLayer_handle,
                                                                      "SetActiveDevice");
    MySendBasicTrajectory = (int(*)(TrajectoryPoint)) GetProcAddress(commandLayer_handle,
                                                                     "SendBasicTrajectory");
    MyGetCartesianCommand = (int(*)(CartesianPosition &)) GetProcAddress(commandLayer_handle,
                                                                         "GetCartesianCommand");

    if ((MyInitAPI == NULL) || (MyCloseAPI == NULL) || (MySendBasicTrajectory == NULL) ||
        (MyGetDevices == NULL) || (MySetActiveDevice == NULL) || (MyGetCartesianCommand == NULL) ||
        (MyMoveHome == NULL) || (MyInitFingers == NULL)){

        cout << "init error/n";
        programResult = 0;
    }
    else{
    	cout << "initialization complete" << endl;
		while (1){
		
        cout << "Halo ini robot kinova! Terdapat beberapa menu seperti : \n1. Susu \n2. Kopi " <<endl ;
        cout << "Input Nilai Anda (1 - 2): ";
 		cin >> nilai;
        int result = (*MyInitAPI)();
        CartesianPosition currentCommand;
        KinovaDevice list[MAX_KINOVA_DEVICE];
        int devicesCount = MyGetDevices(list, result);

        for (int i = 0; i < devicesCount; i++) {
            cout << "robot found: " << list[i].SerialNumber << endl;
            MySetActiveDevice(list[i]);

            MyInitFingers();
            TrajectoryPoint pointToSend;
            pointToSend.InitStruct();
		
            pointToSend.Position.Type = CARTESIAN_POSITION;
			switch(nilai){
				case 1:
					// posisi awal robot untuk topping A
					pointToSend.Position.CartesianPosition.X = -0.156093;
					pointToSend.Position.CartesianPosition.Y = 0.51561;
					pointToSend.Position.CartesianPosition.Z = 0.370455;
					pointToSend.Position.CartesianPosition.ThetaX = -3.01402;
					pointToSend.Position.CartesianPosition.ThetaY = -0.0409602;
					pointToSend.Position.CartesianPosition.ThetaZ = -1.33796;
					pointToSend.Position.Fingers.Finger1 = 2586;
					pointToSend.Position.Fingers.Finger2 = 2514;
					pointToSend.Position.Fingers.Finger3 = 1944;
					MySendBasicTrajectory(pointToSend);
					
					pointToSend.Position.CartesianPosition.X = -0.285054;
					pointToSend.Position.CartesianPosition.Y = 0.515845;
					pointToSend.Position.CartesianPosition.Z = 0.371005;
					pointToSend.Position.CartesianPosition.ThetaX = -3.02631;
					pointToSend.Position.CartesianPosition.ThetaY = -0.0667585;
					pointToSend.Position.CartesianPosition.ThetaZ = -1.54922;
					pointToSend.Position.Fingers.Finger1 = 2586;
					pointToSend.Position.Fingers.Finger2 = 2514;
					pointToSend.Position.Fingers.Finger3 = 1944;
					MySendBasicTrajectory(pointToSend);
					
					pointToSend.Position.CartesianPosition.X = -0.284936;
					pointToSend.Position.CartesianPosition.Y = 0.581884;
					pointToSend.Position.CartesianPosition.Z = 0.051773;
					pointToSend.Position.CartesianPosition.ThetaX = -3.02315;
					pointToSend.Position.CartesianPosition.ThetaY = -0.0611374;
					pointToSend.Position.CartesianPosition.ThetaZ = -1.35605;
					pointToSend.Position.Fingers.Finger1 = 2772;
					pointToSend.Position.Fingers.Finger2 = 2706;
					pointToSend.Position.Fingers.Finger3 = 1944;
					MySendBasicTrajectory(pointToSend);
					
					pointToSend.Position.CartesianPosition.X = -0.114467;
					pointToSend.Position.CartesianPosition.Y = 0.577586;
					pointToSend.Position.CartesianPosition.Z = 0.0456968;
					pointToSend.Position.CartesianPosition.ThetaX = -2.12689;
					pointToSend.Position.CartesianPosition.ThetaY = 1.31841;
					pointToSend.Position.CartesianPosition.ThetaZ = -2.3358;
					pointToSend.Position.Fingers.Finger1 = 2172;
					pointToSend.Position.Fingers.Finger2 = 2208;
					pointToSend.Position.Fingers.Finger3 = 2544;
					MySendBasicTrajectory(pointToSend);
					
					pointToSend.Position.CartesianPosition.X = -0.0104519;
					pointToSend.Position.CartesianPosition.Y = 0.594472;
					pointToSend.Position.CartesianPosition.Z = 0.0457435;
					pointToSend.Position.CartesianPosition.ThetaX = -2.7926;
					pointToSend.Position.CartesianPosition.ThetaY = 1.42669;
					pointToSend.Position.CartesianPosition.ThetaZ = -1.65886;
					pointToSend.Position.Fingers.Finger1 = 2376;
					pointToSend.Position.Fingers.Finger2 = 2370;
					pointToSend.Position.Fingers.Finger3 = 2544;
					MySendBasicTrajectory(pointToSend);
					
					pointToSend.Position.CartesianPosition.X = -0.00977626;
					pointToSend.Position.CartesianPosition.X = -0.0154233;
					pointToSend.Position.CartesianPosition.Y = 0.591095;
					pointToSend.Position.CartesianPosition.Z = 0.0327738;
					pointToSend.Position.CartesianPosition.ThetaX = -2.13408;
					pointToSend.Position.CartesianPosition.ThetaY = 1.38452;
					pointToSend.Position.CartesianPosition.ThetaZ = -2.29788;
					pointToSend.Position.Fingers.Finger1 = 1776;
					pointToSend.Position.Fingers.Finger2 = 1800;
					pointToSend.Position.Fingers.Finger3 = 1098;
					MySendBasicTrajectory(pointToSend);
					
					pointToSend.Position.CartesianPosition.X = 0.0323272;
					pointToSend.Position.CartesianPosition.Y = 0.591436;
					pointToSend.Position.CartesianPosition.Z = 0.0325841;
					pointToSend.Position.CartesianPosition.ThetaX = -2.4307;
					pointToSend.Position.CartesianPosition.ThetaY = 1.44066;
					pointToSend.Position.CartesianPosition.ThetaZ = -1.9968;
					pointToSend.Position.Fingers.Finger1 = 1782;
					pointToSend.Position.Fingers.Finger2 = 1800;
					pointToSend.Position.Fingers.Finger3 = 1110;
					MySendBasicTrajectory(pointToSend);
					
					pointToSend.Position.CartesianPosition.X = 0.0323272;
					pointToSend.Position.CartesianPosition.Y = 0.591436;
					pointToSend.Position.CartesianPosition.Z = 0.0325841;
					pointToSend.Position.CartesianPosition.ThetaX = -2.4307;
					pointToSend.Position.CartesianPosition.ThetaY = 1.44066;
					pointToSend.Position.CartesianPosition.ThetaZ = -1.9968;
					pointToSend.Position.Fingers.Finger1 = 5868;
					pointToSend.Position.Fingers.Finger2 = 6036;
					pointToSend.Position.Fingers.Finger3 = 5028;
					MySendBasicTrajectory(pointToSend);
					
					pointToSend.Position.CartesianPosition.X = 0.0324339;
					pointToSend.Position.CartesianPosition.Y = 0.59115;
					pointToSend.Position.CartesianPosition.Z = 0.125607;
					pointToSend.Position.CartesianPosition.ThetaX = -2.43288;
					pointToSend.Position.CartesianPosition.ThetaY = 1.4407;
					pointToSend.Position.CartesianPosition.ThetaZ = -1.99464;
					pointToSend.Position.Fingers.Finger1 = 5868;
					pointToSend.Position.Fingers.Finger2 = 6030;
					pointToSend.Position.Fingers.Finger3 = 4974;
					MySendBasicTrajectory(pointToSend);
					
					// ngambil
					pointToSend.Position.CartesianPosition.X = 0.239645;
					pointToSend.Position.CartesianPosition.Y = 0.597811;
					pointToSend.Position.CartesianPosition.Z = 0.125703;
					pointToSend.Position.CartesianPosition.ThetaX = 2.36111;
					pointToSend.Position.CartesianPosition.ThetaY = 1.43134;
					pointToSend.Position.CartesianPosition.ThetaZ = -0.496666;
					pointToSend.Position.Fingers.Finger1 = 5868;
					pointToSend.Position.Fingers.Finger2 = 6030;
					pointToSend.Position.Fingers.Finger3 = 4974;
					MySendBasicTrajectory(pointToSend);
					
					pointToSend.Position.CartesianPosition.X = 0.238227;
					pointToSend.Position.CartesianPosition.Y = 0.516021;
					pointToSend.Position.CartesianPosition.Z = 0.125806;
					pointToSend.Position.CartesianPosition.ThetaX = 2.15339;
					pointToSend.Position.CartesianPosition.ThetaY = 1.39044;
					pointToSend.Position.CartesianPosition.ThetaZ = -0.286307;
					pointToSend.Position.Fingers.Finger1 = 5868;
					pointToSend.Position.Fingers.Finger2 = 6030;
					pointToSend.Position.Fingers.Finger3 = 4974;
					MySendBasicTrajectory(pointToSend);
					
					pointToSend.Position.CartesianPosition.X = 0.262547;
					pointToSend.Position.CartesianPosition.Y = 0.515257;
					pointToSend.Position.CartesianPosition.Z = 0.125222;
					pointToSend.Position.CartesianPosition.ThetaX = 2.05;
					pointToSend.Position.CartesianPosition.ThetaY = 1.35629;
					pointToSend.Position.CartesianPosition.ThetaZ = -0.183163;
					pointToSend.Position.Fingers.Finger1 = 5814;
					pointToSend.Position.Fingers.Finger2 = 6000;
					pointToSend.Position.Fingers.Finger3 = 4986;
					MySendBasicTrajectory(pointToSend);
					
					for(i=0;i<10;i++){
					pointToSend.Position.CartesianPosition.X = 0.262407;
					pointToSend.Position.CartesianPosition.Y = 0.51594;
					pointToSend.Position.CartesianPosition.Z = 0.125955;
					pointToSend.Position.CartesianPosition.ThetaX = -2.80604;
					pointToSend.Position.CartesianPosition.ThetaY = -0.181258;
					pointToSend.Position.CartesianPosition.ThetaZ = -1.35783;
					pointToSend.Position.Fingers.Finger1 = 5814;
					pointToSend.Position.Fingers.Finger2 = 6000;
					pointToSend.Position.Fingers.Finger3 = 4986;
					MySendBasicTrajectory(pointToSend);
				}
					pointToSend.Position.CartesianPosition.X = 0.260904;
					pointToSend.Position.CartesianPosition.Y = 0.518446;
					pointToSend.Position.CartesianPosition.Z = 0.129965;
					pointToSend.Position.CartesianPosition.ThetaX = 1.82995;
					pointToSend.Position.CartesianPosition.ThetaY = 1.3597;
					pointToSend.Position.CartesianPosition.ThetaZ = 0.0551489;
					pointToSend.Position.Fingers.Finger1 = 6036;
					pointToSend.Position.Fingers.Finger2 = 6240;
					pointToSend.Position.Fingers.Finger3 = 4986;
					MySendBasicTrajectory(pointToSend);
					
					pointToSend.Position.CartesianPosition.X = 0.0301921;
					pointToSend.Position.CartesianPosition.Y = 0.596215;
					pointToSend.Position.CartesianPosition.Z = 0.130038;
					pointToSend.Position.CartesianPosition.ThetaX = -1.79786;
					pointToSend.Position.CartesianPosition.ThetaY = 1.32961;
					pointToSend.Position.CartesianPosition.ThetaZ = -2.61205;
					pointToSend.Position.Fingers.Finger1 = 6036;
					pointToSend.Position.Fingers.Finger2 = 6240;
					pointToSend.Position.Fingers.Finger3 = 4986;
					MySendBasicTrajectory(pointToSend);
					
					pointToSend.Position.CartesianPosition.X = 0.041156;
					pointToSend.Position.CartesianPosition.Y = 0.580824;
					pointToSend.Position.CartesianPosition.Z = 0.0335265;
					pointToSend.Position.CartesianPosition.ThetaX = -1.81833;
					pointToSend.Position.CartesianPosition.ThetaY = 1.34928;
					pointToSend.Position.CartesianPosition.ThetaZ = -2.59105;
					pointToSend.Position.Fingers.Finger1 = 6036;
					pointToSend.Position.Fingers.Finger2 = 6240;
					pointToSend.Position.Fingers.Finger3 = 4986;
					MySendBasicTrajectory(pointToSend);
					
					pointToSend.Position.CartesianPosition.X = 0.0342215;
					pointToSend.Position.CartesianPosition.Y = 0.580163;
					pointToSend.Position.CartesianPosition.Z = 0.0329364;
					pointToSend.Position.CartesianPosition.ThetaX = -1.80099;
					pointToSend.Position.CartesianPosition.ThetaY = 1.33377;
					pointToSend.Position.CartesianPosition.ThetaZ = -2.69269;
					pointToSend.Position.Fingers.Finger1 = 5154;
					pointToSend.Position.Fingers.Finger2 = 5376;
					pointToSend.Position.Fingers.Finger3 = 4788;
					MySendBasicTrajectory(pointToSend);
					
					pointToSend.Position.CartesianPosition.X = 0.0342215;
					pointToSend.Position.CartesianPosition.Y = 0.580163;
					pointToSend.Position.CartesianPosition.Z = 0.0329364;
					pointToSend.Position.CartesianPosition.ThetaX = -1.80099;
					pointToSend.Position.CartesianPosition.ThetaY = 1.33377;
					pointToSend.Position.CartesianPosition.ThetaZ = -2.69269;
					pointToSend.Position.Fingers.Finger1 = 2460;
					pointToSend.Position.Fingers.Finger2 = 2688;
					pointToSend.Position.Fingers.Finger3 = 2106;
					MySendBasicTrajectory(pointToSend);
					
					pointToSend.Position.CartesianPosition.X = 0.0342215;
					pointToSend.Position.CartesianPosition.Y = 0.580163;
					pointToSend.Position.CartesianPosition.Z = 0.0329364;
					pointToSend.Position.CartesianPosition.ThetaX = -1.80099;
					pointToSend.Position.CartesianPosition.ThetaY = 1.33377;
					pointToSend.Position.CartesianPosition.ThetaZ = -2.69269;
					pointToSend.Position.Fingers.Finger1 = -6;
					pointToSend.Position.Fingers.Finger2 = -6;
					pointToSend.Position.Fingers.Finger3 = -6;
					MySendBasicTrajectory(pointToSend);
					
					pointToSend.Position.CartesianPosition.X = 0.0342925;
					pointToSend.Position.CartesianPosition.Y = 0.579958;
					pointToSend.Position.CartesianPosition.Z = 0.318268;
					pointToSend.Position.CartesianPosition.ThetaX = -1.80247;
					pointToSend.Position.CartesianPosition.ThetaY = 1.33411;
					pointToSend.Position.CartesianPosition.ThetaZ = -2.69124;
					pointToSend.Position.Fingers.Finger1 = -6;
					pointToSend.Position.Fingers.Finger2 = -6;
					pointToSend.Position.Fingers.Finger3 = -6;
					MySendBasicTrajectory(pointToSend);
					// posisi final topping A
					pointToSend.Position.CartesianPosition.X = -0.156093;
					pointToSend.Position.CartesianPosition.Y = 0.51561;
					pointToSend.Position.CartesianPosition.Z = 0.370455;
					pointToSend.Position.CartesianPosition.ThetaX = -3.01402;
					pointToSend.Position.CartesianPosition.ThetaY = -0.0409602;
					pointToSend.Position.CartesianPosition.ThetaZ = -1.33796;
					pointToSend.Position.Fingers.Finger1 = 2586;
					pointToSend.Position.Fingers.Finger2 = 2514;
					pointToSend.Position.Fingers.Finger3 = 1944;
					MySendBasicTrajectory(pointToSend);
					


					/*
					pointToSend.Position.CartesianPosition.X = -0.00919026;
					pointToSend.Position.CartesianPosition.Y = 0.591446;
					pointToSend.Position.CartesianPosition.Z = 0.10197;
					pointToSend.Position.CartesianPosition.ThetaX = -2.16843;
					pointToSend.Position.CartesianPosition.ThetaY = 1.39381;
					pointToSend.Position.CartesianPosition.ThetaZ = -2.34805;
					pointToSend.Position.Fingers.Finger1 = 3864;
					pointToSend.Position.Fingers.Finger2 = 3876;
					pointToSend.Position.Fingers.Finger3 = 2550;
					MySendBasicTrajectory(pointToSend);
					
					pointToSend.Position.CartesianPosition.X = 0.249752;
					pointToSend.Position.CartesianPosition.Y = 0.592229;
					pointToSend.Position.CartesianPosition.Z = 0.102016;
					pointToSend.Position.CartesianPosition.ThetaX = 1.90379;
					pointToSend.Position.CartesianPosition.ThetaY = 1.26255;
					pointToSend.Position.CartesianPosition.ThetaZ = -0.115127;
					pointToSend.Position.Fingers.Finger1 = 3864;
					pointToSend.Position.Fingers.Finger2 = 3876;
					pointToSend.Position.Fingers.Finger3 = 2550;
					MySendBasicTrajectory(pointToSend);
					*/
					
					
				
					break;
				case 2:
					// Posisi awal robot untuk topping B
					pointToSend.Position.CartesianPosition.X = -0.158889;
					pointToSend.Position.CartesianPosition.Y = 0.371213;
					pointToSend.Position.CartesianPosition.Z = 0.370037;
					pointToSend.Position.CartesianPosition.ThetaX = -3.02569;
					pointToSend.Position.CartesianPosition.ThetaY = -0.0950878;
					pointToSend.Position.CartesianPosition.ThetaZ = -1.44043;
					pointToSend.Position.Fingers.Finger1 = 2586;
					pointToSend.Position.Fingers.Finger2 = 2520;
					pointToSend.Position.Fingers.Finger3 = 1950;
					MySendBasicTrajectory(pointToSend);
					
					pointToSend.Position.CartesianPosition.X = -0.160008;
					pointToSend.Position.CartesianPosition.Y = 0.368731;
					pointToSend.Position.CartesianPosition.Z = 0.0499295;
					pointToSend.Position.CartesianPosition.ThetaX = 2.43288;
					pointToSend.Position.CartesianPosition.ThetaY = 1.40065;
					pointToSend.Position.CartesianPosition.ThetaZ = -0.737055;
					pointToSend.Position.Fingers.Finger1 = 2586;
					pointToSend.Position.Fingers.Finger2 = 2520;
					pointToSend.Position.Fingers.Finger3 = 1950;
					MySendBasicTrajectory(pointToSend);
					
					pointToSend.Position.CartesianPosition.X = -0.0125276;
					pointToSend.Position.CartesianPosition.Y = 0.391965;
					pointToSend.Position.CartesianPosition.Z = 0.020022;
					pointToSend.Position.CartesianPosition.ThetaX = 1.91387;
					pointToSend.Position.CartesianPosition.ThetaY = 1.25702;
					pointToSend.Position.CartesianPosition.ThetaZ = -0.186829;
					pointToSend.Position.Fingers.Finger1 = 0;
					pointToSend.Position.Fingers.Finger2 = 0;
					pointToSend.Position.Fingers.Finger3 = -6;
					MySendBasicTrajectory(pointToSend);
					
					pointToSend.Position.CartesianPosition.X = 0.0451998;
					pointToSend.Position.CartesianPosition.Y = 0.392334;
					pointToSend.Position.CartesianPosition.Z = 0.0200219;
					pointToSend.Position.CartesianPosition.ThetaX = 1.80948;
					pointToSend.Position.CartesianPosition.ThetaY = 1.11605;
					pointToSend.Position.CartesianPosition.ThetaZ = -0.0745484;
					pointToSend.Position.Fingers.Finger1 = 0;
					pointToSend.Position.Fingers.Finger2 = 0;
					pointToSend.Position.Fingers.Finger3 = -6;
					MySendBasicTrajectory(pointToSend);
					
					pointToSend.Position.CartesianPosition.X = 0.0451998;
					pointToSend.Position.CartesianPosition.Y = 0.392334;
					pointToSend.Position.CartesianPosition.Z = 0.0200219;
					pointToSend.Position.CartesianPosition.ThetaX = 1.80948;
					pointToSend.Position.CartesianPosition.ThetaY = 1.11605;
					pointToSend.Position.CartesianPosition.ThetaZ = -0.0745484;
					pointToSend.Position.Fingers.Finger1 = 5358;
					pointToSend.Position.Fingers.Finger2 = 5400;
					pointToSend.Position.Fingers.Finger3 = 5394;
					MySendBasicTrajectory(pointToSend);
					
					pointToSend.Position.CartesianPosition.X = 0.0452119;
					pointToSend.Position.CartesianPosition.Y = 0.392156;
					pointToSend.Position.CartesianPosition.Z = 0.190487;
					pointToSend.Position.CartesianPosition.ThetaX = 1.80979;
					pointToSend.Position.CartesianPosition.ThetaY = 1.11564;
					pointToSend.Position.CartesianPosition.ThetaZ = -0.0748651;
					pointToSend.Position.Fingers.Finger1 = 5358;
					pointToSend.Position.Fingers.Finger2 = 5400;
					pointToSend.Position.Fingers.Finger3 = 5394;
					MySendBasicTrajectory(pointToSend);
					
					pointToSend.Position.CartesianPosition.X = 0.281626;
					pointToSend.Position.CartesianPosition.Y = 0.498652;
					pointToSend.Position.CartesianPosition.Z = 0.190613;
					pointToSend.Position.CartesianPosition.ThetaX = 1.76614;
					pointToSend.Position.CartesianPosition.ThetaY = 1.00096;
					pointToSend.Position.CartesianPosition.ThetaZ = -0.024287;
					pointToSend.Position.Fingers.Finger1 = 5358;
					pointToSend.Position.Fingers.Finger2 = 5400;
					pointToSend.Position.Fingers.Finger3 = 5394;
					MySendBasicTrajectory(pointToSend);
					
					pointToSend.Position.CartesianPosition.X = 0.28149;
					pointToSend.Position.CartesianPosition.Y = 0.520093;
					pointToSend.Position.CartesianPosition.Z = 0.157944;
					pointToSend.Position.CartesianPosition.ThetaX = 1.86739;
					pointToSend.Position.CartesianPosition.ThetaY = 1.08791;
					pointToSend.Position.CartesianPosition.ThetaZ = -0.0982426;
					pointToSend.Position.Fingers.Finger1 = 5358;
					pointToSend.Position.Fingers.Finger2 = 5400;
					pointToSend.Position.Fingers.Finger3 = 5394;
					MySendBasicTrajectory(pointToSend);
					
					pointToSend.Position.CartesianPosition.X = 0.281476;
					pointToSend.Position.CartesianPosition.Y = 0.521173;
					pointToSend.Position.CartesianPosition.Z = 0.159393;
					pointToSend.Position.CartesianPosition.ThetaX = -2.68038;
					pointToSend.Position.CartesianPosition.ThetaY = -0.468113;
					pointToSend.Position.CartesianPosition.ThetaZ = -1.0293;
					pointToSend.Position.Fingers.Finger1 = 5358;
					pointToSend.Position.Fingers.Finger2 = 5400;
					pointToSend.Position.Fingers.Finger3 = 5394;
					MySendBasicTrajectory(pointToSend);
					
					pointToSend.Position.CartesianPosition.X = 0.281705;
					pointToSend.Position.CartesianPosition.Y = 0.52247;
					pointToSend.Position.CartesianPosition.Z = 0.161315;
					pointToSend.Position.CartesianPosition.ThetaX = 1.80187;
					pointToSend.Position.CartesianPosition.ThetaY = 1.0959;
					pointToSend.Position.CartesianPosition.ThetaZ = -0.0172264;
					pointToSend.Position.Fingers.Finger1 = 5358;
					pointToSend.Position.Fingers.Finger2 = 5400;
					pointToSend.Position.Fingers.Finger3 = 5394;
					MySendBasicTrajectory(pointToSend);
					
					pointToSend.Position.CartesianPosition.X = 0.0499733;
					pointToSend.Position.CartesianPosition.Y = 0.391392;
					pointToSend.Position.CartesianPosition.Z = 0.194058;
					pointToSend.Position.CartesianPosition.ThetaX = 2.409;
					pointToSend.Position.CartesianPosition.ThetaY = 1.4295;
					pointToSend.Position.CartesianPosition.ThetaZ = -0.644176;
					pointToSend.Position.Fingers.Finger1 = 5358;
					pointToSend.Position.Fingers.Finger2 = 5400;
					pointToSend.Position.Fingers.Finger3 = 5394;
					MySendBasicTrajectory(pointToSend);
					
					pointToSend.Position.CartesianPosition.X = 0.049328;
					pointToSend.Position.CartesianPosition.Y = 0.379984;
					pointToSend.Position.CartesianPosition.Z = 0.0130508;
					pointToSend.Position.CartesianPosition.ThetaX = 2.39709;
					pointToSend.Position.CartesianPosition.ThetaY = 1.4278;
					pointToSend.Position.CartesianPosition.ThetaZ = -0.63208;
					pointToSend.Position.Fingers.Finger1 = 5358;
					pointToSend.Position.Fingers.Finger2 = 5400;
					pointToSend.Position.Fingers.Finger3 = 5394;
					MySendBasicTrajectory(pointToSend);
					
					pointToSend.Position.CartesianPosition.X = 0.049328;
					pointToSend.Position.CartesianPosition.Y = 0.379984;
					pointToSend.Position.CartesianPosition.Z = 0.0130508;
					pointToSend.Position.CartesianPosition.ThetaX = 2.39709;
					pointToSend.Position.CartesianPosition.ThetaY = 1.4278;
					pointToSend.Position.CartesianPosition.ThetaZ = -0.63208;
					pointToSend.Position.Fingers.Finger1 = 2514;
					pointToSend.Position.Fingers.Finger2 = 2580;
					pointToSend.Position.Fingers.Finger3 = 2562;
					MySendBasicTrajectory(pointToSend);
					
					pointToSend.Position.CartesianPosition.X = 0.0409934;
					pointToSend.Position.CartesianPosition.Y = 0.379987;
					pointToSend.Position.CartesianPosition.Z = 0.0130524;
					pointToSend.Position.CartesianPosition.ThetaX = 2.51959;
					pointToSend.Position.CartesianPosition.ThetaY = 1.44148;
					pointToSend.Position.CartesianPosition.ThetaZ = -0.755728;
					pointToSend.Position.Fingers.Finger1 = 2412;
					pointToSend.Position.Fingers.Finger2 = 2484;
					pointToSend.Position.Fingers.Finger3 = 2466;
					MySendBasicTrajectory(pointToSend);
					
					pointToSend.Position.CartesianPosition.X = 0.0409934;
					pointToSend.Position.CartesianPosition.Y = 0.379987;
					pointToSend.Position.CartesianPosition.Z = 0.0130524;
					pointToSend.Position.CartesianPosition.ThetaX = 2.51959;
					pointToSend.Position.CartesianPosition.ThetaY = 1.44148;
					pointToSend.Position.CartesianPosition.ThetaZ = -0.755728;
					pointToSend.Position.Fingers.Finger1 = -6;
					pointToSend.Position.Fingers.Finger2 = -6;
					pointToSend.Position.Fingers.Finger3 = -6;
					MySendBasicTrajectory(pointToSend);
					
					// Posisi final Robot untuk topping B
					pointToSend.Position.CartesianPosition.X = -0.156093;
					pointToSend.Position.CartesianPosition.Y = 0.51561;
					pointToSend.Position.CartesianPosition.Z = 0.370455;
					pointToSend.Position.CartesianPosition.ThetaX = -3.01402;
					pointToSend.Position.CartesianPosition.ThetaY = -0.0409602;
					pointToSend.Position.CartesianPosition.ThetaZ = -1.33796;
					pointToSend.Position.Fingers.Finger1 = 2586;
					pointToSend.Position.Fingers.Finger2 = 2514;
					pointToSend.Position.Fingers.Finger3 = 1944;
					MySendBasicTrajectory(pointToSend);
					break;
				default:
					cout<< "input yang bener kontol" << endl ;
					break;
		}
        }
		

        cout << endl;
        result = (*MyCloseAPI)();
        programResult = 1;
    }

    FreeLibrary(commandLayer_handle);
    return programResult;
}
}

/*
pointToSend.Position.CartesianPosition.X = 0.434979;
pointToSend.Position.CartesianPosition.Y = 0.207725;
pointToSend.Position.CartesianPosition.Z = 0.3324;
pointToSend.Position.CartesianPosition.ThetaX = 3.0391;
pointToSend.Position.CartesianPosition.ThetaY = 0.211504;
pointToSend.Position.CartesianPosition.ThetaZ = -3.01929;
pointToSend.Position.Fingers.Finger1 = 6;
pointToSend.Position.Fingers.Finger2 = 6;
pointToSend.Position.Fingers.Finger3 = 528;
MySendBasicTrajectory(pointToSend);

pointToSend.Position.CartesianPosition.X = 0.374475;
pointToSend.Position.CartesianPosition.Y = 0.457243;
pointToSend.Position.CartesianPosition.Z = 0.324432;
pointToSend.Position.CartesianPosition.ThetaX = -3.11697;
pointToSend.Position.CartesianPosition.ThetaY = 0.195773;
pointToSend.Position.CartesianPosition.ThetaZ = 1.82137;
pointToSend.Position.Fingers.Finger1 = 12;
pointToSend.Position.Fingers.Finger2 = 12;
pointToSend.Position.Fingers.Finger3 = 1296;
MySendBasicTrajectory(pointToSend);



pointToSend.Position.CartesianPosition.X = 0.370336;
pointToSend.Position.CartesianPosition.Y = 0.466823;
pointToSend.Position.CartesianPosition.Z = 0.0142053;
pointToSend.Position.CartesianPosition.ThetaX = -3.08939;
pointToSend.Position.CartesianPosition.ThetaY = 0.120287;
pointToSend.Position.CartesianPosition.ThetaZ = 1.87008;
pointToSend.Position.Fingers.Finger1 = 18;
pointToSend.Position.Fingers.Finger2 = 24;
pointToSend.Position.Fingers.Finger3 = 1290;
MySendBasicTrajectory(pointToSend);

pointToSend.Position.CartesianPosition.X = 0.370336;
pointToSend.Position.CartesianPosition.Y = 0.466823;
pointToSend.Position.CartesianPosition.Z = 0.0142053;
pointToSend.Position.CartesianPosition.ThetaX = -3.08939;
pointToSend.Position.CartesianPosition.ThetaY = 0.120287;
pointToSend.Position.CartesianPosition.ThetaZ = 1.87008;
pointToSend.Position.Fingers.Finger1 = 4110;
pointToSend.Position.Fingers.Finger2 = 4140;
pointToSend.Position.Fingers.Finger3 = 1134;
MySendBasicTrajectory(pointToSend);

pointToSend.Position.CartesianPosition.X = 0.390933;
pointToSend.Position.CartesianPosition.Y = 0.46419;
pointToSend.Position.CartesianPosition.Z = 0.225776;
pointToSend.Position.CartesianPosition.ThetaX = -3.09185;
pointToSend.Position.CartesianPosition.ThetaY = 0.120859;
pointToSend.Position.CartesianPosition.ThetaZ = 1.78186;
pointToSend.Position.Fingers.Finger1 = 4110;
pointToSend.Position.Fingers.Finger2 = 4140;
pointToSend.Position.Fingers.Finger3 = 1134;
MySendBasicTrajectory(pointToSend);

pointToSend.Position.CartesianPosition.X = 0.221487;
pointToSend.Position.CartesianPosition.Y = 0.316831;
pointToSend.Position.CartesianPosition.Z = 0.226981;
pointToSend.Position.CartesianPosition.ThetaX = -3.08086;
pointToSend.Position.CartesianPosition.ThetaY = 0.115451;
pointToSend.Position.CartesianPosition.ThetaZ = 1.69168;
pointToSend.Position.Fingers.Finger1 = 4110;
pointToSend.Position.Fingers.Finger2 = 4140;
pointToSend.Position.Fingers.Finger3 = 1134;
MySendBasicTrajectory(pointToSend);

pointToSend.Position.CartesianPosition.X = 0.221765;
pointToSend.Position.CartesianPosition.Y = 0.295925;
pointToSend.Position.CartesianPosition.Z = 0.0678605;
pointToSend.Position.CartesianPosition.ThetaX = -3.08084;
pointToSend.Position.CartesianPosition.ThetaY = 0.115953;
pointToSend.Position.CartesianPosition.ThetaZ = 1.69183;
pointToSend.Position.Fingers.Finger1 = 4110;
pointToSend.Position.Fingers.Finger2 = 4140;
pointToSend.Position.Fingers.Finger3 = 1134;
MySendBasicTrajectory(pointToSend);

pointToSend.Position.CartesianPosition.X = 0.221765;
pointToSend.Position.CartesianPosition.Y = 0.295925;
pointToSend.Position.CartesianPosition.Z = 0.0678605;
pointToSend.Position.CartesianPosition.ThetaX = -3.08084;
pointToSend.Position.CartesianPosition.ThetaY = 0.115953;
pointToSend.Position.CartesianPosition.ThetaZ = 1.69183;
pointToSend.Position.Fingers.Finger1 = 0;
pointToSend.Position.Fingers.Finger2 = 0;
pointToSend.Position.Fingers.Finger3 = 1134;
MySendBasicTrajectory(pointToSend);

pointToSend.Position.CartesianPosition.X = 0.222265;
pointToSend.Position.CartesianPosition.Y = 0.293958;
pointToSend.Position.CartesianPosition.Z = 0.25332;
pointToSend.Position.CartesianPosition.ThetaX = -3.08217;
pointToSend.Position.CartesianPosition.ThetaY = 0.123602;
pointToSend.Position.CartesianPosition.ThetaZ = 1.79185;
pointToSend.Position.Fingers.Finger1 = 0;
pointToSend.Position.Fingers.Finger2 = 0;
pointToSend.Position.Fingers.Finger3 = 1134;
MySendBasicTrajectory(pointToSend);

*/





