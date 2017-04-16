def loopDetection(head):
	fast, slow = head

	while fast is not slow:
		slow = slow.next
		fast = fast.next.next

	slow = head

	while fast is not slow:
		fast = fast.next
		slow = slow.next

	return slow