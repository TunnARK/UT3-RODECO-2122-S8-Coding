	 ES_2 <= (EP_1 and not(Po)) or (EP_2 and not(not(Po)));

	 ES_0 <= (EP_1 and Accept and not(Po)) or (EP_2 and not(Accept)) or (EP_2 and Cancel and Po) or (EP_0 and not(Accept and not(Po))) or (EP_0 and not(not(Accept))) or (EP_0 and not(Cancel and Po));

	 ES_1 <= (EP_0 and not(Po)) or (EP_2 and not(Cancel)) or (EP_1 and not(not(Po))) or (EP_1 and not(not(Cancel)));

