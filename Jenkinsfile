pipeline {
    agent {
		label 'Unreal425'
	}
	options {
		buildDiscarder logRotator(artifactDaysToKeepStr: '', artifactNumToKeepStr: '', daysToKeepStr: '', numToKeepStr: '10')
		disableConcurrentBuilds()
	}
	environment {
		WEBHOOK = credentials('DiscordWebhook')
	}
	
    stages{
        stage('scm'){
			steps{
				checkout scm
			}
		}
		stage('Build: Prep'){
			steps{
				bat label: 'Prepare', script: '"%Unreal 4.25_HOME%\\%Unreal_BuildTool%" -projectfiles -project="%WORKSPACE%\\UESpringJam\\UESpringJam.uproject" -dx12 -game -rocket -progress'
			}
		}
		stage('Build: Build'){
			steps{
				bat label: 'Build', script: '"%Unreal 4.25_HOME%\\%Unreal_RunUAT%" BuildCookRun -project="%WORKSPACE%\\UESpringJam\\UESpringJam.uproject" -dx12 -noP4 -platform=Win64 -clientconfig=Development -cook -allmaps -build -stage -pak -archive -archivedirectory="%WORKSPACE%\\Builds"'
			}
		}
		stage('Build: Cook'){
			steps{
				bat label: 'cook', script: '"%Unreal 4.25_HOME%\\%Unreal_RunUAT%" BuildCookRun -project="%WORKSPACE%\\UESpringJam\\UESpringJam.uproject" -dx12 -noP4 -platform=Win64 -clientconfig=Development -cook -allmaps -NoCompile -stage -pak -archive -archivedirectory="%WORKSPACE%\\Builds"'
			}
		}
    }
	post {
		always {
			archiveArtifacts 'Builds/**/*.*'
			cleanWs notFailBuild: true
			sendDiscord()
		}
	}
}

@NonCPS
def sendDiscord(){
	def changeString = ""
	
	def changeSets = currentBuild.changeSets
	for (int i = 0; i < changeSets.size(); i++){
		def entries = changeSets[i].items
		for (int j = 0; j < entries.length; j++){
			def entry = entries[j]
			truncated_ID = entry.commitId.take(7)
			truncated_msg = entry.msg.take(100)
			changeString += "\n- `${truncated_ID}` *${truncated_msg} -  ${entry.author}*"
		}
	}
	
	if (!changeString) {
        changeString = "\n\n - No new changes"
    }
    
	discordSend description: "**Build:** ${env.BUILD_NUMBER}\n**Status:** ${currentBuild.currentResult}\n\n**Changes:**${changeString}\n\n**Artifacts:**\n- ${env.BUILD_URL}artifact/",
	footer: '',
	image: '',
	link: env.BUILD_URL,
	result: currentBuild.currentResult,
	thumbnail: '',
	title: env.BRANCH_NAME,
	webhookURL: env.WEBHOOK
}
