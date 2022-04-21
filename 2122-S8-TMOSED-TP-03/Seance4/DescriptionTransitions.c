	 ES_2 = EP_1 and Po = '1' or EP_2 and not(Po = '1')

	 ES_0 = EP_1 and Accept = '1' and Po = '0' or EP_2 and Accept = '0' or EP_2 and Cancel = '1' and Po = '1' or EP_0 and not(Accept = '1' and Po = '0') or EP_0 and not(Accept = '0') or EP_0 and not(Cancel = '1' and Po = '1')

	 ES_1 = EP_0 and Po = '0' or EP_2 and Cancel = '0' or EP_1 and not(Po = '0') or EP_1 and not(Cancel = '0')

