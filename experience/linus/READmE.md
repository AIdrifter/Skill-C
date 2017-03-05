$31 = (struct node *) 0x200d070
(gdb) p (*indirect)->next->next->next->next
$32 = (struct node *) 0x200d090
(gdb) p (*indirect)->next->next->next->next->next
$33 = (struct node *) 0x0
(gdb) p (*indirect)->next->next->next->next
$34 = (struct node *) 0x200d090
(gdb) p &(*indirect)->next
$35 = (struct node **) 0x200d010
(gdb) p (*indirect)->next
$36 = (struct node *) 0x200d030
(gdb) p (*indirect)
$37 = (Node *) 0x200d010
(gdb) p (*indirect)->next
$38 = (struct node *) 0x200d030
(gdb) p &(*indirect)->next
$39 = (struct node **) 0x200d010

