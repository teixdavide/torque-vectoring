
% Initialize parameters automatically when the model gets loaded.
%
% In the File / Model properties dialog of the model, on the tab labeled
% Callbacks, set 'MySusp_SpringSystem_RTW_params' as the Model's pre-load function.
%
% An alternative way via the Matlab command line would be
%   set_param('MySusp_SpringSystem_RTW', 'PreLoadFcn', 'MySusp_SpringSystem_RTW_params');

disp('Executing MySusp_SpringSystem_RTW_params.m for parameter initialization');

l0_FL = 0.657;
Stiffness_FL = 60000;
l0_FR = 0.657;
Stiffness_FR = 60000;
l0_RL = 0.647;
Stiffness_RL = 70000;
l0_RR = 0.647;
Stiffness_RR = 70000;

