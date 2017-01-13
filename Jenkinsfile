node {
	stage('Build') {
		echo 'Build Stage';
		qmake string-test.pro;
		make;
	}
	stage('Send') {
		echo 'Send Stage';
	}
}
