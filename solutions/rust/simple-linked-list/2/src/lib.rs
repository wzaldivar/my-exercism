struct SimpleLinkedNode<T> {
    value: T,
    next: Option<Box<SimpleLinkedNode<T>>>,
}
pub struct SimpleLinkedList<T> {
    head: Option<Box<SimpleLinkedNode<T>>>,
}

impl<T> SimpleLinkedNode<T> {
    fn new(value: T, next: Option<Box<SimpleLinkedNode<T>>>) -> Self {
        SimpleLinkedNode { value, next }
    }
}

impl<T> SimpleLinkedList<T> {
    pub fn new() -> Self {
        SimpleLinkedList::<T> { head: None }
    }

    // You may be wondering why it's necessary to have is_empty()
    // when it can easily be determined from len().
    // It's good custom to have both because len() can be expensive for some types,
    // whereas is_empty() is almost always cheap.
    // (Also ask yourself whether len() is expensive for SimpleLinkedList)
    pub fn is_empty(&self) -> bool {
        self.head.is_none()
    }

    pub fn len(&self) -> usize {
        let mut len = 0;
        let mut current_node = self.head.as_ref();
        while let Some(node) = current_node {
            len += 1;
            current_node = node.next.as_ref();
        }
        len
    }

    pub fn push(&mut self, _element: T) {
        let new_node = Box::new(SimpleLinkedNode::new(_element, self.head.take()));
        self.head = Some(new_node)
    }

    pub fn pop(&mut self) -> Option<T> {
        self.head.take().map(|node| {
            self.head = node.next;
            node.value
        })
    }

    pub fn peek(&self) -> Option<&T> {
        self.head.as_ref().map(|node| &node.value)
    }

    #[must_use]
    pub fn rev(self) -> SimpleLinkedList<T> {
        let mut rev_list = SimpleLinkedList::<T>::new();
        let mut current_node = self.head;
        while let Some(node) = current_node {
            rev_list.push(node.value);
            current_node = node.next;
        }
        rev_list
    }
}

impl<T> FromIterator<T> for SimpleLinkedList<T> {
    fn from_iter<I: IntoIterator<Item = T>>(_iter: I) -> Self {
        let mut list = SimpleLinkedList::<T>::new();
        for element in _iter {
            list.push(element);
        }
        list
    }
}

// In general, it would be preferable to implement IntoIterator for SimpleLinkedList<T>
// instead of implementing an explicit conversion to a vector. This is because, together,
// FromIterator and IntoIterator enable conversion between arbitrary collections.
//
// The reason this exercise's API includes an explicit conversion to Vec<T> instead
// of IntoIterator is that implementing that interface is fairly complicated, and
// demands more of the student than we expect at this point in the track.
//
// Please note that the "front" of the linked list should correspond to the "back"
// of the vector as far as the tests are concerned.

impl<T> From<SimpleLinkedList<T>> for Vec<T> {
    fn from(mut _linked_list: SimpleLinkedList<T>) -> Vec<T> {
        let mut vec = Vec::new();
        let mut rev_list = _linked_list.rev();
        while let Some(element) = rev_list.pop() {
            vec.push(element);
        }
        vec
    }
}
