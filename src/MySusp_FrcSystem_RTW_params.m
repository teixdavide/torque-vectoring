
% Initialize parameters automatically when the model gets loaded.
%
% In the File / Model properties dialog of the model, on the tab labeled
% Callbacks, set 'MySusp_FrcSystem_RTW_params' as the Model's pre-load function.
%
% An alternative way via the Matlab command line would be
%   set_param('MySusp_FrcSystem_RTW', 'PreLoadFcn', 'MySusp_FrcSystem_RTW_params');

disp('Executing MySusp_FrcSystem_RTW_params.m for parameter initialization');

% Spring Parameter
l0_Spring_FL = 0.657;
Stiffness_Spring_FL = 60000;
l0_Spring_FR = 0.657;
Stiffness_Spring_FR = 60000;
l0_Spring_RL = 0.647;
Stiffness_Spring_RL = 70000;
l0_Spring_RR = 0.647;
Stiffness_Spring_RR = 70000;

% Damper Parameter
Damping_Push_FL = 5000;
Damping_Pull_FL = 10000;
Damping_Push_FR = 5000;
Damping_Pull_FR = 10000;
Damping_Push_RL = 21000;
Damping_Pull_RL = 60000;
Damping_Push_RR = 21000;
Damping_Pull_RR = 60000;

% Buffer Parameter
Stiffness_Buffer_Push_FL = 50000;
Stiffness_Buffer_Pull_FL = 50000;
l0_Buffer_Push_FL = -0.055;
l0_Buffer_Pull_FL = 0.09;

Stiffness_Buffer_Push_FR = 50000;
Stiffness_Buffer_Pull_FR = 50000;
l0_Buffer_Push_FR = -0.055;
l0_Buffer_Pull_FR = 0.09;

Stiffness_Buffer_Push_RL = 50000;
Stiffness_Buffer_Pull_RL = 50000;
l0_Buffer_Push_RL = -0.08;
l0_Buffer_Pull_RL = 0.065;

Stiffness_Buffer_Push_RR = 50000;
Stiffness_Buffer_Pull_RR = 50000;
l0_Buffer_Push_RR = -0.08;
l0_Buffer_Pull_RR = 0.065;

% Stabi  Parameter
Stiffness_Stabi_F = 15000;
Stiffness_Stabi_R = 15000;
