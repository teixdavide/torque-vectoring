
% Initialize parameters automatically when the model gets loaded.
%
% In the File / Model properties dialog of the model, on the tab labeled
% Callbacks, set 'MySusp_DamperSystem_RTW_params' as the Model's pre-load function.
%
% An alternative way via the Matlab command line would be
%   set_param('MySusp_DamperSystem_RTW', 'PreLoadFcn', 'MySusp_DamperSystem_RTW_params');

disp('Executing MySusp_DamperSystem_RTW_params.m for parameter initialization');

Damping_Push_FL = 5000;
Damping_Pull_FL = 10000;
Damping_Push_FR = 5000;
Damping_Pull_FR = 10000;
Damping_Push_RL = 21000;
Damping_Pull_RL = 60000;
Damping_Push_RR = 21000;
Damping_Pull_RR = 60000;
