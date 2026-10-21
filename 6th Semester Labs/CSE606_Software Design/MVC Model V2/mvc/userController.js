setInterval(fetchUserDetails, 5000);

function registerUser() {

    const name = document.getElementById('name').value;
    const email = document.getElementById('email').value;
    const password = document.getElementById('psw').value;
    const phone = document.getElementById('phone').value;

    // Display the form data in the console
    console.log("Name:", name);
    console.log("Email:", email);
    console.log("Password:", password);
    console.log("Phone:", phone);

    // Create an object with the form data
    const formData = {
        name: name,
        email: email,
        password: password,
        phone: phone
    };

    // Send a POST request using Axios
    axios.post('http://localhost:5000/api/users/reg', formData)
        .then(response => {
            console.log('Response:', response.data);
            // Handle successful response here
        })
        .catch(error => {
            console.error('Error:', error);
            // Handle error here
        });

    document.getElementById('name').value = '';
    document.getElementById('email').value = '';
    document.getElementById('psw').value = '';
    document.getElementById('phone').value = '';

}

function fetchUserDetails() {
    axios.get('http://localhost:5000/api/users/all')
        .then(response => {
            const userList = response.data; // Make sure response.data is an array
            console.log('Data fetched....');

            if (Array.isArray(userList)) { // Check if userList is an array
                const userListContainer = document.getElementById('userList');

                // Clear the previous content
                userListContainer.innerHTML = '';

                // Populate the list with user details
                userList.forEach(user => {
                    const listItem = document.createElement('li');
                    listItem.textContent = `Name: ${user.name}, Email: ${user.email}, Phone: ${user.phone}`;
                    userListContainer.appendChild(listItem);
                });
            } else {
                console.error('Invalid user data format:', userList);
            }
        })
        .catch(error => {
            console.error('Error:', error);
            // Handle error here
        });
}