{
    float DEG2RAD = 0.017453293;
	Node thisNode = getNode();
	Node parent = thisNode.getParent();

    // Disable the node - it will get re-enabled when the state is updated
    // in the Door class.
	
	// This is blocking :) By setting the enable to 0, the expression stops execution.
	// Should use the state parameter (Opening.. Closing.. etc) to drive the node?
    //thisNode.setEnabled(0);
	
    // Our controller and parameter properties attached to this Expression 
	//     we KNOW them so dont waste time CHECKING!!!!
	Property prop = thisNode.getProperty();

	int currId = prop.findParameter("CurrPos");
	float currPos = prop.getParameterFloat(currId);
	int prevId = prop.findParameter("PrevPos");
	float prevPos = prop.getParameterFloat(prevId);

	if(prevPos == currPos) return;
	prop.setParameterFloat(prevId, currPos);
	
	// Init check - if the EndPos is not yet set, then save this EndPos from the node!!
	int endposId = prop.findParameter("EndPos");
	dvec3 endpos = dvec3(prop.getParameterVec3(endposId));
	
	// We should never have an object / door more than 100 km away!!!
	if(endpos.x == 99999)
	{
		endpos = parent.getPosition();
		prop.setParameterVec3(endposId, endpos);
	}
	
	// If Slide set then apply based on state
	int typeId = prop.findState("DoorType");
		
	// Sliding method
	int doorType = prop.getState(typeId);
	
	int maxdistId = prop.findParameter("MaxDistance");
	float maxdist = prop.getParameterFloat(maxdistId);
	int dirId = prop.findParameter("Direction");
	float dir = prop.getParameterFloat(dirId) * DEG2RAD;

	switch(doorType)
	{
	case 0:   // popOpen door type
    {
    	int popDistId = prop.findParameter("PopDistance");
        float popDist = prop.getParameterFloat(popDistId);
    	int popAmountId = prop.findParameter("PopAmount");
        float popAmount = prop.getParameterFloat(popAmountId);
        
        if(currPos < popAmount)
        {
            float diry = sin(dir) * popDist * currPos/popAmount;
            float dirx = cos(dir) * popDist * currPos/popAmount;
            
		    endpos.x += dirx;
		    endpos.y += diry;
		    parent.setPosition(endpos);
        }
        else
        {
            float pdiry = sin(dir) * popDist;
            float pdirx = cos(dir) * popDist;
            float dirx = sin(dir) * maxdist * (currPos - popAmount) / (1.0 - popAmount);
            float diry = cos(dir) * maxdist * (currPos - popAmount) / (1.0 - popAmount);

		    endpos.x += dirx + pdirx;
		    endpos.y += diry + pdiry;
		    parent.setPosition(endpos);
        }
    }
	break;
	case 1:   // Slide door type
    {
        float dirx = sin(dir) * maxdist * currPos;
        float diry = cos(dir) * maxdist * currPos;

		endpos.x += dirx;
		endpos.y += diry;
		parent.setPosition(endpos);
    }
	break;
	case 2:   // Turn door type
	break;
	}
}