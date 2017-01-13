node {
	stage('Checkout') {
		checkout scm
	}
	stage('Build') {
		echo 'Build Stage';
		try {
			sh 'qmake ll-test.pro'
			sh 'make'
		} catch(Exception e) {
			sh 'g++ tests.cpp -std=c++11'
		}
	}
	stage('Run') {
		testResults = sh(returnStdout: true, script: './a.out').trim()
		echo testResults
	}
	stage('Send') {
		echo 'Send Stage'
		def to = emailextrecipients([
	        "jrcarlson@smu.edu",
	        [$class: 'RequesterRecipientProvider']
		])
		if(to != null && !to.isEmpty()) {
		    mail to: to, subject: "Build has finished with ${currentBuild.result}",
		            body: "See ${env.BUILD_URL}.\n${testResults}"
		}
	}
}
