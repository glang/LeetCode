def intersect(n1, n2):
	len1, len2 = 1, 1
	run1, run2 = n1, n2

	while run1.next is not None:
		len1 += 1
		run1 = run1.next
	
	while run2.next is not None:
		len2 += 1
		run2 = run2.next

	if run1 is not run2:
		return None

	longer = n1 if len1 > len2 else n2
	shorter = n2 if len1 > len2 else n1

	for i in range(abs(len1 - len2)):
		longer = longer.next

	while longer is not None:
		if longer is shorter:
			return longer
		longer = longer.next
		shorter = shorter.next