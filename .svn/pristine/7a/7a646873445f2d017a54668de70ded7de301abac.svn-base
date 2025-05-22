function [success, check_time] = run_model_checks(model)
    t_start = clock;
    disp('Running model checks');
    load_system(model);
    reference_models = find_mdlrefs(model);
    success = true;
    
    %Run checks for broken library links and models not using reference
    %configs
    broken_links = [];
    non_reference_configs = [];
    for i = 1:length(reference_models)
        rm = reference_models{i};
        already_loaded = bdIsLoaded(rm);
        if(~already_loaded)
            load_system(rm);
        end
        
        broken_links = [broken_links; libinfo(rm, 'LinkStatus', 'inactive')];
        
        if(~isa(getActiveConfigSet(rm), 'Simulink.ConfigSetRef'))
            non_reference_configs = [non_reference_configs; reference_models(i)];
        end
        
        % we want to close without save, however only for models that 
        % weren't already open otherwise we may be throwing away 
        % legitimate changes
        if(~already_loaded)
            close_system(rm, 0);
        end
    end
    
    %Generate error for broken library links
    if(length(broken_links) > 0)
        success = false;
        str = 'The following blocks have broken library links:\n';
        for i = 1:length(broken_links)
            str=[str ' * ' broken_links(i).Block '\n'];
        end
        disp(sprintf(str));
    end
    
    %Generate error for non reference configs
    if(length(non_reference_configs) > 0)
        success = false;
        str = 'The following models are not using reference configs:\n';
        for i = 1:length(non_reference_configs)
            str=[str ' * ' non_reference_configs{i} '\n'];
        end
        disp(sprintf(str));
    end
    check_time = etime(clock, t_start);
end
        