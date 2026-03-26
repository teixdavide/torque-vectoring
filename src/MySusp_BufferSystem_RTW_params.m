
% Initialize parameters automatically when the model gets loaded.
%
% In the File / Model properties dialog of the model, on the tab labeled
% Callbacks, set 'MySusp_BufferSystem_RTW_params' as the Model's pre-load function.
%
% An alternative way via the Matlab command line would be
%   set_param('MySusp_BufferSystem_RTW', 'PreLoadFcn', 'MySusp_BufferSystem_RTW_params');

disp('Executing MySusp_BufferSystem_RTW_params.m for parameter initialization');

Stiffness_Push_FL = 50000;
Stiffness_Pull_FL = 50000;
l0_Push_FL = -0.055;
l0_Pull_FL = 0.09;

Stiffness_Push_FR = 50000;
Stiffness_Pull_FR = 50000;
l0_Push_FR = -0.055;
l0_Pull_FR = 0.09;

Stiffness_Push_RL = 50000;
Stiffness_Pull_RL = 50000;
l0_Push_RL = -0.08;
l0_Pull_RL = 0.065;

Stiffness_Push_RR = 50000;
Stiffness_Pull_RR = 50000;
l0_Push_RR = -0.08;
l0_Pull_RR = 0.065;
